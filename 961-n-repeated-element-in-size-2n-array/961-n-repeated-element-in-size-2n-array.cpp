class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,res;
        while(1){
            if(nums[i]==nums[i+1]){
                res= nums[i];
                break;
            }
            i++;
        }
        return res;
    }
};