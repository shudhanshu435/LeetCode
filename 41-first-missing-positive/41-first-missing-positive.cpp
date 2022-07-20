class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size(),one = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 1)one = 1;
            else
            if(nums[i] <= 0 || nums[i] > len)nums[i] = 1;
        }
        
        if(one == 0)return 1;
        
        for(int i = 0; i < len; i++){
            cout<<nums[i]<< " ";
        }
        
        for(int i = 0; i < len; i++){
            int ind = abs(nums[i]) - 1;
            if(nums[ind] > 0)nums[ind] = -1 * nums[ind];
        }
        
        for(int i = 0;i < len; i++){
            if(nums[i] > 0)return i+1;
        }
        
        return len+1;
    }
};