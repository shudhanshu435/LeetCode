class Solution {
public:
    int dp[501][501];
    int rec(string &s, int i, int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=rec(s,i+1,j-1);

        return dp[i][j]=1+min(rec(s,i+1,j),rec(s,i,j-1));
    }
    int minInsertions(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return rec(s,0,n-1);
    }
};