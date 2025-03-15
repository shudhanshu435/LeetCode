class Solution {
public:
    bool ispos(vector<int>&nums, int k, int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;i++;
            }
        }
        if(cnt>=k)return 1;
        return 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=INT_MAX,r=0;
        for(int i=0;i<nums.size();i++){
            l=min(l,nums[i]);
            r=max(r,nums[i]);
        }
        int ans=0;
        while(l<=r){
            int mid=r-(r-l)/2;
            if(ispos(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};