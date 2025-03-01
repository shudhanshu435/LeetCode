class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int z=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)v.push_back(nums[i]);
            else z++;
        }
        while(z--)v.push_back(0);
        return v;

    }
};