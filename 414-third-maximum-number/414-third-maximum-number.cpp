class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)s.insert(nums[i]);
        int m=s.size();
        sort(nums.begin(),nums.end());
        if(m==1)return nums[0];
        if(m==2)return nums[nums.size()-1];
        reverse(nums.begin(),nums.end());
        int t=1,ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                ans=nums[i];
                t++;
                if(t==3)break;
            }
        }
        return ans;
    }
};