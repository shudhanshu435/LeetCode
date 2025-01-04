class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto m:mp){
            vector<int>v=m.second;
            int n=v.size();
            if(n>1){
                unordered_set<char>ss;
                for(int i=v[0]+1;i<v[n-1];i++){
                    ss.insert(s[i]);
                }
                ans+=ss.size();
            }
        }
        return ans;

    }
};