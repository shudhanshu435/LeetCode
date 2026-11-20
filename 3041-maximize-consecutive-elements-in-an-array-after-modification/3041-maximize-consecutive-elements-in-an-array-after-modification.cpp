class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int>dp;
        int ans=1;
        for (int x:nums) {
            dp[x+1]=dp[x]+1;   // raise x to x+1
            dp[x]=dp[x-1]+1; // keep x as is
            ans=max({ans,dp[x],dp[x+1]});
        }
        return ans;
    }
};

// 1 1 1 2 5
// 1 2 5

// 0 3 3 3 5 6 7 8 10 12 18
// 0 3 5 6 7 8 10 12 18
                    
// 1 1 4 1 1 1