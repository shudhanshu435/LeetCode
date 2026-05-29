class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=nums[0];
        for(auto i:nums){
            int m=i;
            int c=0;
            while(m){
                c+=m%10;m/=10;
            }
            ans=min(ans,c);
        }
        return ans;
    }
};