class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        int ans=0;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                cnt++;
                ans=max(ans,cnt);
            }
            else if(nums[i]>maxi){
                maxi=nums[i];
                cnt=1;
                ans=1;
            }
            else cnt=0;
        }
        return ans;
    }
};