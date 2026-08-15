class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int z=0;
        int n=nums.size();
        for(auto i:nums){
            x=x^i;
            z+=(i==0);
        }
        if(z==n)return 0;
        if(x==0)return n-1;
        return n;
    }
};