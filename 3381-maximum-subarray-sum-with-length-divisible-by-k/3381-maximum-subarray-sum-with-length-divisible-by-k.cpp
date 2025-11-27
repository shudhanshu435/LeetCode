class Solution {
public:

    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=LLONG_MIN;
     
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<k;i++){
            long long curr=0;
            int l=i,j;
            while(l<n and l+k-1<n){
                j=l+k-1;
                long long sum=pre[j]-((l>0)?pre[l-1]:0);
                curr=max(sum,curr+sum);
                ans=max(ans,curr);
                l+=k;
            }
        }
        return ans;
    }
};