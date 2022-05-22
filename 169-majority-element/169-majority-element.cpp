class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=0,s=0;
        for(int i=0;i<nums.size();i++){
            if(c==0)s=nums[i];
            if(nums[i]==s)c++;
            else c--;
        }
        return s;
    }
};