class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        vector<bool>ans(n);
        for(int i=0;i<n;i++){
            x=((x<<1)+nums[i])%5;
            ans[i]=(x==0);
        }
        return ans;
    }
};