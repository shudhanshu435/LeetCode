class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.length();
        int i=0;
        for(;i<k;i++){
            mp[s[i]]++;
        }
        if(n==k){
            if(mp.size()==1)return 1;
            return 0;
        }

        if(mp.size()==1){
            if(s[i]!=s[i-1])return 1;
        }
        set<char>ss;
        int l;
        for(l=n-k;l<n;l++)ss.insert(s[l]);
        if(ss.size()==1 and s[l-1]!=s[n-k-1])return 1;   

        int kk=0;
        int le=0,rt=k+1;
        for(;i<n-1;i++){
            mp[s[i]]++;
            mp[s[kk]]--;
            if(mp[s[kk]]==0)mp.erase(s[kk]);
            if(mp.size()==1 and s[le]!=s[le+1] and s[rt]!=s[rt-1])return 1;
            le++;rt++;
            kk++;
        }
        return 0;
    }
};