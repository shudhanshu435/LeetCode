class Solution {
public:
int mod=1000000007;
    int totalpaths(vector<string>& grid, int K) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(K+1,0)));
        dp[0][0][0]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0)continue;
                if(grid[i][j]=='X')continue;
                int v=grid[i][j]-'0';
                for(int k=v;k<=K;k++){
                    if(i>0)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-v])%mod;
                    if(j>0)dp[i][j][k]=(dp[i][j][k]+dp[i][j-1][k-v])%mod;
                    if(i>0 and j>0)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-v])%mod;
                }
            }
        }
        return (dp[n-1][n-1][K])%mod;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        board[0][0]='0';
        board[n-1][n-1]='0';
        dp[0][0]=0;
        for(int i=1;i<n;i++){
            if(board[0][i]=='X' or dp[0][i-1]==-1)dp[0][i]=-1;
            else dp[0][i]=(board[0][i]-'0')+dp[0][i-1];
        }

        for(int i=1;i<n;i++){
            if(board[i][0]=='X' or dp[i-1][0]==-1)dp[i][0]=-1;
            else dp[i][0]=(board[i][0]-'0')+dp[i-1][0];;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(board[i][j]=='X')dp[i][j]=-1;
                else{
                    int best=max({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                    if(best==-1)dp[i][j]=-1;
                    else dp[i][j]=(board[i][j]-'0')+best;
                }
            }
        }
        // cout<<dp[n-1][n-1]<<endl;
        if(dp[n-1][n-1]==-1)return {0,0};
        return {dp[n-1][n-1], totalpaths(board,dp[n-1][n-1])};

        return {};
    }
};