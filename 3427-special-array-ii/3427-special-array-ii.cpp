class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            if((nums[i]%2==0 and nums[i-1]%2==0) or (nums[i]%2!=0 and nums[i-1]%2!=0))
                dp[i]=dp[i-1]+1;
            else dp[i]=dp[i-1];
        }
        vector<bool>vec;
        for(auto v:queries){
            if(dp[v[0]]-dp[v[1]]==0)vec.push_back(true);
            else vec.push_back(false);
        }
        return vec;
    }
};