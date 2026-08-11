class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]+1==nums[i+1])sum+=nums[i+1];
            else break;
        }
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            if(i>sum)return sum;
            if(i==sum)sum++;
        }
        return sum;
    }
};