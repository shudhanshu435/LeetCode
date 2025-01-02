class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>vec;
        string vow="aeiou";
        for(auto i:words){
            if(find(vow.begin(),vow.end(),i[0])!=vow.end() and find(vow.begin(),vow.end(),i.back())!=vow.end())vec.push_back(1);
            else vec.push_back(0);
        }
        for(int i=1;i<vec.size();i++){
            vec[i]=vec[i-1]+vec[i];
        }
        vector<int>ans;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            if(l==0)ans.push_back(vec[r]);
            else{
                ans.push_back(vec[r]-vec[l-1]);
            }
        }
        return ans;

        return vec;
    }
};