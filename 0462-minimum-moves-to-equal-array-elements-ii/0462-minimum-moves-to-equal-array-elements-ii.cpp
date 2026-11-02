class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n&1){
            int m=nums[n/2];
            long long ans=0;
            for(int i:nums){
                ans+=abs(i-m);
            }
            return ans;
        }
        else{
            long long a=nums[n/2-1];
            long long b=nums[n/2];
            long long avg=(a+b)/2;
            long long ans=0;
            for(int i:nums){
                ans+=abs(i-avg);
            }
            return ans;
        }
    }
};