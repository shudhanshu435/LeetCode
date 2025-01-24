class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n=paragraph.size();
        for(int i=0;i<n;i++){
            if(isalpha(paragraph[i]))paragraph[i]=tolower(paragraph[i]);
            else paragraph[i]=' ';
        }
        cout<<paragraph<<endl;
        stringstream ss(paragraph);
        string word;
        unordered_map<string,int>mp;

        while(ss>>word){
            if(!isalpha(word.back()))word.pop_back();
            if(find(banned.begin(),banned.end(),word)==banned.end())
                mp[word]++;
        }
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        string ans="";
        int maxx=0;
        for(auto i:mp){
            if(i.second>maxx){
                maxx=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};