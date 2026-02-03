class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        bool b=1;
        while(i<n-1 and nums[i]<nums[i+1]){
            i++;
            b=0;
        }
        if(b)return 0;
        b=1;
        while(i<n-1 and nums[i]>nums[i+1]){
            i++;
            b=0;
        }
        if(b)return 0;
        b=1;
        while(i<n-1 and nums[i]<nums[i+1]){
            i++;
            b=0;
        }
        if(b)return 0;
        return i==n-1;

    }
};