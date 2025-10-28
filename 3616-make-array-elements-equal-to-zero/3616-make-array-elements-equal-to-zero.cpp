class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(nums[i]==0){
                if(curr==sum-curr)ans+=2;
                else if(abs(curr-(sum-curr))==1)ans+=1;
            }
        }
        return ans;
    }
};