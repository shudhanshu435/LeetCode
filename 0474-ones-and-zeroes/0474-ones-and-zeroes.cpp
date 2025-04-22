class Solution {
public:
    int solve(vector<string>& strs, int ind, int m, int n, vector<vector<vector<int>>> &dp){
        if(ind==strs.size())return 0;
        if(dp[ind][m][n]!=-1)return dp[ind][m][n];

        int zero=count(strs[ind].begin(),strs[ind].end(),'0');
        int one=strs[ind].size()-zero;

        //not pick
        int notpick=solve(strs,ind+1,m,n,dp);

        //pick
        int pick=0;
        if(m>=zero and n>=one){
            pick=1+solve(strs,ind+1,m-zero,n-one,dp);
        }

        return dp[ind][m][n]=max(pick,notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<vector<int>>>dp(size, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(strs,0,m,n,dp);
    }
};

/*

"10","0001","111001","1","0"
0-1   0-3    0-2     0-0  0-1
1-1   1-1    1-4     1-1  1-0

*/