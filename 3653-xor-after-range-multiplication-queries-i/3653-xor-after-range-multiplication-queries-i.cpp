class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int x=0;
        int n=nums.size();
        for(auto &i:queries){
            for(int j=i[0];j<=n and j<=i[1];j+=i[2]){
                nums[j]=(nums[j]*1ll*i[3])%1000000007;
            }
        }
        for(auto &i:nums)x=x^i;
        return x;
    }
};