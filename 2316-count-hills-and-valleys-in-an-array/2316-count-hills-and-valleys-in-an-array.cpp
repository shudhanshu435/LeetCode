class Solution {
public:
    int countHillValley(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        // for(auto i:nums)cout<<i<<" ";
        int c=0;
        // cout<<endl<<nums.size()<<endl;
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i]>nums[i-1] and nums[i]>nums[i+1]) or (nums[i]<nums[i-1] and nums[i]<nums[i+1]))c++;
        }
        return c;
    }
};