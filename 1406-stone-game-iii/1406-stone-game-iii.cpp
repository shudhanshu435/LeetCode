class Solution {
public:
int n;
vector<int>dp;
    int solve(vector<int>&s, int i){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int res=s[i]-solve(s,i+1);
        if(i+1<n)res=max(res,s[i]+s[i+1]-solve(s,i+2));
        if(i+2<n)res=max(res,s[i]+s[i+1]+s[i+2]-solve(s,i+3));
        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& s) {
        n=s.size();
        dp.resize(n+1,-1);
        int diff=solve(s,0);
        if(diff<0)return "Bob";
        else if(diff>0)return "Alice";
        return "Tie";
    }
};