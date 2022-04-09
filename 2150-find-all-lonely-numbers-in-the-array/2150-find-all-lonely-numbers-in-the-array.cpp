class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>vec;
        sort(nums.begin(),nums.end());
        if(nums.size()==1)vec.push_back(nums[0]);
        else {
            if(nums[1]-nums[0]>=2)vec.push_back(nums[0]);
            if(nums[nums.size()-1]-nums[nums.size()-2]>=2)vec.push_back(nums[nums.size()-1]);
            for(int i=1;i<nums.size()-1;i++){
                if((nums[i]-nums[i-1])>=2 && (nums[i+1]-nums[i])>=2)vec.push_back(nums[i]);
            }
        }
        return vec;
    }
};