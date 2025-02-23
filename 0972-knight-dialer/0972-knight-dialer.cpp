class Solution {
public:
    int mod=1e9+7;
    int solve(int n, int cell, unordered_map<int,vector<int>>&mp,vector<vector<int>>&dp){
        if(n==0)return 1;
        if(dp[n][cell]!=-1)return dp[n][cell];
        int ans=0;
        for(auto& i:mp[cell]){
            ans=(ans+solve(n-1,i,mp,dp))%mod;
        }
        return dp[n][cell]=ans;
    }
    int knightDialer(int n) {
        vector<vector<int>>dp(5001,vector<int>(10,-1));
        unordered_map<int,vector<int>>mp;
        mp[1]={6,8};
        mp[2]={7,9};
        mp[3]={4,8};
        mp[4]={3,9,0};
        mp[5]={};
        mp[6]={1,7,0};
        mp[7]={2,6};
        mp[8]={1,3};
        mp[9]={4,2};
        mp[0]={4,6};

        int res=0;
        for(int i=0;i<10;i++){
            res=(res+solve(n-1,i,mp,dp))%mod;
        }
        return res;
    }
};