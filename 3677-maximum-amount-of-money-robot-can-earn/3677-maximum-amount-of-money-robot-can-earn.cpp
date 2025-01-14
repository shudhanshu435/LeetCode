class Solution {
public:
    int dp[501][501][3];
    int solve(int ri, int ci, int nl, vector<vector<int>>& coins, int n, int m){
        // int n=coins.size();
        // int m=coins[0].size();
        if(ri==n-1 and ci==m-1){
            if(nl>0 and coins[ri][ci]<0)return 0;
            return coins[ri][ci];
        }
        if(ri>=n or ci>=m)return INT_MIN;

        if(dp[ri][ci][nl]!=INT_MIN)return dp[ri][ci][nl];

        int right=solve(ri,ci+1,nl,coins,n,m);
        int down=solve(ri+1,ci,nl,coins,n,m);

        int maxcoins=coins[ri][ci]+max(right,down);

        if(nl>0 and coins[ri][ci]<0){
            right=solve(ri,ci+1,nl-1,coins,n,m);
            down=solve(ri+1,ci,nl-1,coins,n,m);
            maxcoins=max({maxcoins,right,down});
        }

        return dp[ri][ci][nl]=maxcoins;


    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        return solve(0,0,2,coins,n,m);

        return 0;
    }
};