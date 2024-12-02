class Solution {
public:
    int solve(int ind, vector<int>&cost, vector<int>&memo){
        if(ind>=cost.size())return 0;
        if(memo[ind]!=-1)return memo[ind];
        int onestep=solve(ind+1,cost,memo);
        int twostep=solve(ind+2,cost,memo);
        return memo[ind]=min(onestep,twostep)+cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>memo(n,-1);
        return min(solve(0, cost, memo),solve(1, cost, memo));
    }
};