class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back(nums[nums[i]]);
        }return vec;
    }
};