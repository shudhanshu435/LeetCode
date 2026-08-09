class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(vector<int>&piles, int p, int i, int m){
        if(i>=n)return 0;
        int res=(p==1)?-1:INT_MAX;
        int st=0;
        if(dp[p][i][m]!=-1)return dp[p][i][m];
        for(int x=1;x<=min(2*m,n-i);x++){
            st+=piles[i+x-1];
            if(p==1)res=max(res,st+solve(piles,0,i+x,max(m,x)));
            else res=min(res,solve(piles,1,i+x,max(m,x)));
        }
        return dp[p][i][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1);
    }
};