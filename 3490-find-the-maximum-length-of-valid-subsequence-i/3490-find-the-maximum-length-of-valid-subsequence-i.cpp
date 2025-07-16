class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int num=nums[0];
        int cnt=1,ev=0,od=0;
        if(nums[0]&1)od++;
        else ev++;
        for(int i=1;i<nums.size();i++){
            if((nums[i]+num)%2!=0){
                cnt++;
                num=nums[i];
            }
            if(nums[i]&1)od++;
            else ev++;
        }
        return max({cnt,ev,od});
    }
};