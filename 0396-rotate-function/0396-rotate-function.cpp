class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int>ans;
        ans=nums;
        // 4 3 2 6 4 3 2
        int sum=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum+=i*nums[i];
        }
        int res=0;
        int actsum=accumulate(nums.begin(),nums.end(),0);
        int k=0;
        for(auto i:nums)ans.push_back(i);
        ans.pop_back();
        res=sum;
        for(int i=n;i<2*n-1;i++){
            sum+=(n-1)*ans[i]-(actsum-nums[k++]);
            // cout<<sum<<endl;
            res=max(res,sum);
        }
        return res;
    }
};