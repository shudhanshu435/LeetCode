class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        unordered_set<int>s;
        unordered_set<int>s2;
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j)s.insert(nums[i]^nums[j]);
        }
        for(auto i:s) {
            for(auto n:nums)s2.insert(i^n);
        }
        return s2.size();
    }
};