class Solution {
public:
    long long  dp[5001][4][4][4];
    int mod=1e9+7;
    int rec(int x, int a, int b, int c){
        if(x==0)return 1;

        if(dp[x][a][b][c]!=-1)return dp[x][a][b][c];
        long long ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(i==j or j==k)continue;
                    if(i==a or j==b or k==c)continue;
                    ans=(ans+(rec(x-1,i,j,k)))%mod;
                }
            }
        }
        return dp[x][a][b][c]=ans;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n,3,3,3);
    }
};