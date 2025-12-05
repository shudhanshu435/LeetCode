class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int cnt=0,curr=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            curr+=nums[i];
            sum-=nums[i];
            if((curr-sum)%2==0)cnt++;
        }
        return cnt;
    }
};