class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)z++;
            else if(z!=0){
                ans+=z*1ll*(z+1)/2;
                z=0;
            }
        }
        ans+=z*1ll*(z+1)/2;
        return ans;
    }
};