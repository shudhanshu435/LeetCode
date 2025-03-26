class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int>vec(n+1,0);
        for(int i=1;i<n+1;i++)vec[i]=vec[i-1]+nums[i-1];
        // for(auto i:vec)cout<<i<<" ";
        // cout<<endl;
        int mini=INT_MAX;
        for(int i=l;i<=r;i++){
            for(int j=i;j<=n;j++){
                int sum=vec[j]-vec[j-i];
                if(sum>0)mini=min(mini,sum);
            }
        }
        if(mini==INT_MAX)return -1;
        return mini;
    }
};