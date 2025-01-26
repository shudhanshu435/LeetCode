class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int cnt=0;
        int n=nums.size();
        int sum1=0;
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];
            sum-=nums[i];
            if((sum-sum1)%2==0)cnt++;
        }
        return cnt;
    }
};