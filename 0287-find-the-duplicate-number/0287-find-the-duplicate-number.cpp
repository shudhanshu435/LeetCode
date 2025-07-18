class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=slow=nums[0];
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)break;
        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};