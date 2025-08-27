class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto i:nums)x^=i;
        int k=0;
        while(x%2==0){
            k++;
            x/=2;
        }
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<k))a^=nums[i];
            else b^=nums[i];
        }
        return {a,b};
    }
};