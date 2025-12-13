class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int dup=0,sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                dup=nums[i];
            }
            else sum+=nums[i];
        }
        return {dup,n*(n+1)/2-sum};
    }
};