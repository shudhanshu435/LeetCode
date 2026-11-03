class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        int maxi=*max_element(nums.begin(),nums.end());
        return maxi*n-s;
    }
};