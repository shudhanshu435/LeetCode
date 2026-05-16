class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int n=nums.size();
        while(l<r and nums[l]==nums[r])l++;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[n-1])l=mid+1;
            else if(nums[mid]<=nums[n-1])r=mid-1;
        }
        return nums[min(n-1,l)];
    }
};