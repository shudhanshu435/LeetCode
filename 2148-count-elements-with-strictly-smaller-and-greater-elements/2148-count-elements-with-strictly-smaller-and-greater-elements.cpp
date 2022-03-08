class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=1;i<nums.size()-1;i++){
            if((nums[0]<nums[i]) && (nums[i]<nums[nums.size()-1]))cnt++;
        }return cnt;
    }
};