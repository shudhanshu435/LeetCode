class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=nums[0],curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                curr+=nums[i];
            }
            else{
                maxi=max(maxi,curr);
                curr=nums[i];
            }
        }
        maxi=max(maxi,curr);
        return maxi;
    }
};