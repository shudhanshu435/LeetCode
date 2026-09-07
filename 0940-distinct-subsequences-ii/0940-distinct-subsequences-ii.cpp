class Solution {
public:
    int mod=1000000007;
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int>vec(26,-1);
        vector<long long>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(vec[s[i-1]-'a']!=-1){
                dp[i]=(2*dp[i-1] - dp[vec[s[i-1]-'a']-1] + mod)%mod;
            }
            else dp[i]=(2*dp[i-1])%mod;
            vec[s[i-1]-'a']=i;
        }
        return (dp[n]-1+mod)%mod;
    }
};


