class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0,b=0;
        if(nums[nums.size()-1]<0)return nums[nums.size()-1];
        if(nums[0]>=0)return nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                a=nums[i-1];
                b=nums[i];
                break;
            }
        }
        if(abs(a)<abs(b))return a;
        else return b;
    }
};