class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int sum=0,maxi=0,r=nums.size(),c=nums[0].size();
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end());
        }
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                maxi=(nums[j][i]>maxi)?nums[j][i]:maxi;
            }
            sum+=maxi;
            maxi=0;
        }
        return sum;
    }
};