class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int cnt=0;
        if(nums[0]>0)cnt++;
        long long sum=0;
        sum+=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0)cnt++;
            else break;
        }
        return cnt;
    }
};