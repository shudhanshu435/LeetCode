class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        string word;
        vector<int>v1;
        while(getline(ss1,word,'.'))v1.push_back(stoi(word));
        stringstream ss2(version2);
        vector<int>v2;
        while(getline(ss2,word,'.'))v2.push_back(stoi(word));
        while(!v1.empty() and v1.back()==0)v1.pop_back();
        while(!v2.empty() and v2.back()==0)v2.pop_back();
        int i=0,j=0;
        // for(auto i:v1)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:v2)cout<<i<<" ";
        // cout<<endl;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]<v2[j])return -1;
            else if(v1[i]>v2[j])return 1;
            i++;j++;
        }
        if(i==v1.size() and j==v2.size())return 0;
        if(i==v1.size())return -1;
        return 1;
    }
};