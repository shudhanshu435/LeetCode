class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int z=0;
        if(nums[0]==0)z++;
        ans+=z;
        for(int i=1;i<nums.size();i++){
            // if(nums[i]==0)z++;
            // else if(z!=0){
            //     ans+=z*1ll*(z+1)/2;
            //     z=0;
            // }
            if(nums[i]==0 and nums[i-1]==0){
                z=z+1;
            }
            else if(nums[i]==0){
                z=1;
            }
            else z=0;
            ans+=z;

            // cout<<i<< " "<<ans<<endl;
        }
        return ans;
    }
};