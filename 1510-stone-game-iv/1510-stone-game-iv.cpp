class Solution {
public:
    vector<int>dp;
    bool win(int n){
        if(n==0)return false;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!win(n-i*i)){
                return dp[n]=true;
            }
        }
        return dp[n]=0;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return win(n);
    }
};