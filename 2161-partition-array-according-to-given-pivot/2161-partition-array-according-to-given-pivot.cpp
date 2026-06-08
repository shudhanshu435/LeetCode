class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int ll=0,rr=n-1;
        for(int i=0,j=n-1;i<n and j>=0;i++,j--){
            if(nums[i]<pivot){
                ans[ll]=nums[i];
                ll++;
            }
            if(nums[j]>pivot){
                ans[rr]=nums[j];
                rr--;
            }
        }
        while(ll<=rr){
            ans[ll]=pivot;
            ll++;
        }

        return ans;
    }
};