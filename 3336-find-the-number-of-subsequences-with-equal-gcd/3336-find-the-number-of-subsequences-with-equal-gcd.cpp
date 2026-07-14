class Solution {
public:
    const int mod=1000000007;
    long long solve(vector<int>& nums, int i, int s1, int s2, vector<vector<vector<long long>>>&dp){
        if(i==nums.size()){
            if(s1!=0 and s2!=0)return s1==s2;
            return 0;
        }
        if(dp[i][s1][s2]!=-1)return dp[i][s1][s2];
        long long skip=solve(nums,i+1,s1,s2,dp);
        long long seq1=solve(nums,i+1,__gcd(s1,nums[i]),s2,dp);
        long long seq2=solve(nums,i+1,s1,__gcd(s2,nums[i]),dp);

        return dp[i][s1][s2] = (skip+seq1+seq2)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(maxi+1,vector<long long>(maxi+1,-1)));
        return (int)solve(nums,0,0,0,dp)%mod;
    }
};