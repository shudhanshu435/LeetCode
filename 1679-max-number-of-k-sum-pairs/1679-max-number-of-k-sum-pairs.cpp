class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l=0,cnt=0;
        sort(nums.begin(),nums.end());
        int r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==k){
                l++;
                r--;
                cnt++;
            }
            else if(nums[l]+nums[r]>k)r--;
            else l++;
        }
        return cnt;
    }
};
