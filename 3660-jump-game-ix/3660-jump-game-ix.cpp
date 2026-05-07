class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(nums[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=min(nums[i],right[i+1]);
        }
        vector<int>ans(n);
        ans[n-1]=left[n-1];
        for(int i=n-2;i>=0;i--){
            if(left[i]<=right[i+1])ans[i]=left[i];
            else ans[i]=ans[i+1];
        }
        return ans;
    }
};