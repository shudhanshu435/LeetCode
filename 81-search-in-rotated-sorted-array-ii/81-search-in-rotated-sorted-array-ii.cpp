class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]<target)l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};