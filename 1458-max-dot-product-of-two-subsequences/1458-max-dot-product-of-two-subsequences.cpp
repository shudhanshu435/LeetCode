class Solution {
public:
    int n,m;
    vector<vector<long long>>dp;
    int solve(int i, int j, vector<int>&nums1, vector<int>&nums2){
        if(i==n or j==m)return -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        long long t=nums1[i]*1ll*nums2[j] + max(0,solve(i+1,j+1,nums1,nums2));
        long long s1=solve(i+1,j,nums1,nums2);
        long long s2=solve(i,j+1,nums1,nums2);

        return dp[i][j]=max({t,s1,s2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        dp.assign(n,vector<long long>(m,-1));
        return solve(0,0,nums1,nums2);
    }
};