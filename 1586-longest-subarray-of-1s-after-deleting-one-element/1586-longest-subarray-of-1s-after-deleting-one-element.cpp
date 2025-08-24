class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum=0,ans=0;
        int k=0,z=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           if(nums[i]==0)z++;
           ans=max(sum,ans);
           while(z==2){
            if(nums[k++]==0)z--;
            else sum--;
           } 
           ans=max(sum,ans);
        }
        if(ans==nums.size())return ans-1;
        return ans;
    }
};