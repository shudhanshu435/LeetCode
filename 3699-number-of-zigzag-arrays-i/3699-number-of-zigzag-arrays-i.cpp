class Solution {
public:
    using ll = long long;
    int zigZagArrays(int n, int l, int r) {
        ll mod=1e9+7,res=0;
        vector<vector<ll>>dp(2,vector<ll>(r+2));
        vector<vector<ll>>ndp(2,vector<ll>(r+2));
        for(int j=l;j<=r;++j)
            dp[0][j]=dp[1][j]=1;
        for(int i=n-2;i>=0;--i){
            vector<ll>pref(r+3),suff(r+3);
            for(int j=l;j<=r;++j)
                pref[j]=(pref[j-1]+dp[1][j])%mod;
            for(int j=r;j>=l;--j) 
                suff[j]=(suff[j+1]+dp[0][j])%mod;
            for(int j=l;j<=r;++j){
                ndp[0][j]=pref[j-1]%mod;
                ndp[1][j]=suff[j+1]%mod;
            }
            swap(dp,ndp);
        }
        for(int j=l;j<=r;++j)
            res=(res+dp[0][j]+dp[1][j])%mod;
        return res;
    }
};