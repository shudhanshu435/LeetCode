class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                if(j-i+1>=l and j-i+1<=r and s>0)ans=min(ans,s);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};