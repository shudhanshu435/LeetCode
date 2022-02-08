class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>nve;
        vector<int>pve;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)pve.push_back(nums[i]);
            else nve.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<pve.size();i++){
            nums.push_back(pve[i]);
            nums.push_back(nve[i]);
        }
        return nums;
    }
};