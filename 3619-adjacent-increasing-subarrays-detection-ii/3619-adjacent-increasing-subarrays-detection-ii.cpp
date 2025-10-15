class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cnt=1;
        int ans=INT_MIN,ans2=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                cnt++;
                ans2=max(cnt/2,ans2);
            }
            else{
                ans=min(ans,cnt);
                ans2=max(ans2,ans);
                ans=cnt;
                cnt=1;
            }
        }
        ans=min(ans,cnt);
        ans2=max(ans2,ans);
        return ans2;
    }
};