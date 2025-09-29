class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0,sum2=0;
        int i;
        for(i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                sum+=nums[i];
            }
            else break;
        }
        int k=i+1;
        while(k+1<n){
            if(nums[k]<=nums[k+1])return -1ll;
            else sum2+=nums[k];
            k++;
        }
        if(k==n)return abs(nums[i]-sum);
        sum2+=nums[n-1];
        cout<<sum<<" jj "<<sum2<<endl;
        return abs(max(sum,sum2)-min(sum,sum2)-nums[i]);

    }
};