class Solution {
public:
    int dp[501][501];
    int rec(vector<int>&piles, int i, int j){
        if(i>j)return 0;
        //take
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(piles[i]+rec(piles,i+2,j),piles[j]+rec(piles,i,j-2));

    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size()-1;
        memset(dp,-1,sizeof(dp));
        return rec(piles,0,n);
    }
};