class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l=-1,r;
        int mini=INT_MAX,maxi=INT_MIN;
        int n=nums.size();
        if(n==1)return 1;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]==mini or nums[i]==maxi){
                if(l==-1)l=i;
                else r=i;
            }
        }
        return min({r+1,n-l,n-r+l+1});
    }
};