class Solution {
public:
    int func(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(i<0 and j<0)return 1;
        if(i>=0 and j<0)return 0;
        if(i<0 and j>=0){
            while(j>=0){
                if(p[j]!='*')return 0;
                j--;
            }
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==p[j] or p[j]=='?'){
            return dp[i][j]=func(i-1,j-1,s,p,dp);
        }

        if(j>=0 and p[j]=='*'){
            return dp[i][j]=func(i,j-1,s,p,dp) or func(i-1,j,s,p,dp);
        }

        return dp[i][j]= 0;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();    
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,p,dp);

    }
};