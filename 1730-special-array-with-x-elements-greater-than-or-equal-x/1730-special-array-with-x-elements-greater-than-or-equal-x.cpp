class Solution {
public:
    int bin(vector<int>& nums, int mid){
        int i=0,j=nums.size()-1,n=j+1;
        while(i<=j){
            int midd=(i+j)/2;
            if(nums[midd]==mid and (midd-1>=0 and nums[midd-1]!=nums[midd]))return n-midd;
            else if(nums[midd]<mid)i=midd+1;
            else j=midd-1;
        }
        return n-i;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=nums[n-1];
        while(l<=r){
            int mid=(l+r)/2;
            int curr=bin(nums,mid+1);
            if(curr==(mid+1))return mid+1;
            else if(curr>(mid+1))l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};