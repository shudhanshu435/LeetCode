class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        while(1){
            while(i<n){
                if(nums[i]!=0)i++;
                else break;
            }
            j=i;
            while(j<n){
                if(nums[j]==0)j++;
                else break;
            }
            if(i!=n and j!=n)swap(nums[i],nums[j]);
            else break;
        }
    }
};