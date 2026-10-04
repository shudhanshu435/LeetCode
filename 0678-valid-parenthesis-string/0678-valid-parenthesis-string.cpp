class Solution {
public:
    int dp[101][101];
    bool rec(string &s, int mini, int i, int n){
        if(mini<0)return 0;
        if(i==n)return mini==0;
        if(dp[mini][i]!=-1)return dp[mini][i];

        if(s[i]=='(')return dp[mini][i]=rec(s,mini+1,i+1,n);
        else if(s[i]==')')return dp[mini][i]=rec(s,mini-1,i+1,n);
        else return dp[mini][i]= rec(s,mini+1,i+1,n)|| rec(s,mini-1,i+1,n)|| rec(s,mini,i+1,n);

    }
    bool checkValidString(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return rec(s,0,0,n);
    }
};