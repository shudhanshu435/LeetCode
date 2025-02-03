class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1;
        int lon=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
                dec=1;
            }
            else if(nums[i]>nums[i+1]){
                dec++;
                inc=1;
            }
            else{
                dec=1,inc=1;
            }
            lon=max({lon,dec,inc});
        }
        return lon;
    }
};