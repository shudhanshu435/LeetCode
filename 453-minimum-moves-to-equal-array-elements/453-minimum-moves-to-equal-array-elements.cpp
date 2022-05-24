class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            ans+=nums[i]-nums[0];
        }
        return ans;
    }
};          