class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>diff(n);
        diff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            diff[i]=min(diff[i+1],nums[i]);
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-diff[i]<=k)return i;
        }
        return -1;
    }
};