class Solution {
public:
    // 7 8 9 10 11 12 1 2 3 4 5 6
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int n=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<nums[n-1]){
                if(target<=nums[n-1] and nums[mid]<target)l=mid+1;
                else r=mid-1;
            }
            else if(nums[mid]>=nums[n-1]){
                if(nums[n-1]>=target or nums[mid]<target)l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};