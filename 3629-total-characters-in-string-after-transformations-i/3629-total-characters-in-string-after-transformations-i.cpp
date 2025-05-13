class Solution {
public:
    const int MOD=1000000007;
    int lengthAfterTransformations(string s, int t) {
        // unordered_map<char,long long>mp;
        vector<int>mp(26,0);
        for(char &i:s){
            mp[i-'a']++;
        }
        while(t--){
            // unordered_map<char,long long>mp2;
            vector<int>mp2(26,0);
            for(int i=0;i<26;i++){
                char ch=i+'a';
                int fr=mp[i];
                if(ch=='z'){
                    mp2['a'-'a']=(mp2['a'-'a']+fr)%MOD;
                    mp2['b'-'a']=(mp2['b'-'a']+fr)%MOD;
                }
                else{
                    mp2[(ch+1)-'a']=(mp2[(ch+1)-'a']+fr)%MOD;
                }
            }
            mp=move(mp2);
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+mp[i])%MOD;
        }

        return ans;
    }
};
/*

zzzaaabc

abcz
311
bc
3

*/