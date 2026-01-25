class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int i=k-1;
        int n=nums.size();
        while(i<n){
            mini=min(mini,nums[i]-nums[i-(k-1)]);
            i++;
        }
        return mini;
    }
};