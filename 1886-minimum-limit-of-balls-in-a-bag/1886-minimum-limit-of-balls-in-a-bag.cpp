class Solution {
public:
    bool ispos(vector<int>&nums, int maxop, int mid){
        int tt=0;
        for(auto &num:nums){
            int op=ceil((double)num/mid)-1;
            tt+=op;
        }
        return tt<=maxop;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int mini=1,maxi=*max_element(nums.begin(),nums.end());

        int res=maxi;

        while(mini<=maxi){
            int mid=(mini+(maxi-mini)/2);
            if(ispos(nums, maxOperations,mid)==true){
                res=mid;
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
        }
        return res;
    }
};