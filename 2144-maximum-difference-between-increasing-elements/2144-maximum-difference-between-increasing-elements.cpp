class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=0,ans=-1;
        for(int i=nums.size()-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            if(i-1 >=0 && nums[i-1]<maxi)ans=max(ans,maxi-nums[i-1]);
        }
        return ans;
    }
};