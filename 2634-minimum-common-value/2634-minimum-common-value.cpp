class Solution {
public:
    bool bin(vector<int>&nums, int m){
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==m)return true;
            else if(nums[mid]>m)j=mid-1;
            else i=mid+1;
        }
        return 0;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        for(auto i:nums1){
            if(bin(nums2,i))return i;
        }
        return -1;
    }
};