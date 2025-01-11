class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mp;
        if(s.length()<k)return 0;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int odd=0;
        for(auto m:mp){
            if(m.second%2!=0)odd++;
        }
        if(odd>k)return 0;
        return 1;
    }
};