class Solution {
public:
    bool pos(vector<int>&nums, long long mid){
        long long a=nums[0];
        long long b;
        for(int i=1;i<nums.size();i++){
            if(a>mid)return 0;
            b=nums[i]-(mid-a);
            a=b;
        }
        if(a>mid)return 0;
        return 1;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int i=0,j=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(pos(nums,mid)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};