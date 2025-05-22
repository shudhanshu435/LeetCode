class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>vec;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)vec.push_back(nums[i]);
            else cnt++;
        }
        for(int i=0;i<cnt;i++)vec.push_back(0);
        for(int i=0;i<nums.size();i++){
            nums[i]=vec[i];
        }
    }
};