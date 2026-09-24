class Solution {
public:
    int s(int n){
        if(n==0)return 0;
        return n%10 + s(n/10);
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(s(nums[i])==i)return i;
        }
        return -1;
    }
};