class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)return nums;
        int one=0;
        vector<int>ans;
        int i;
        for(i=1;i<k;i++){
            if(nums[i]-nums[i-1]==1)one++;
        }
        if(one==k-1)ans.push_back(nums[k-1]);
        else ans.push_back(-1);
        int x=1;
        for(;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1)one++;
            if(nums[x]-nums[x-1]==1)one--;
            x++;
            if(one==k-1)ans.push_back(nums[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};