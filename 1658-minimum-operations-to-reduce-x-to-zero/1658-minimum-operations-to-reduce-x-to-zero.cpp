class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<long long>vec(n);
        vec[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            vec[i]=nums[i]+vec[i+1];
        }
        
        if(vec[0]<x)return -1;
        reverse(vec.begin(),vec.end());
        // 1 2

        int i1=INT_MAX;
        long long lef=0;
        for(int i=0;i<n;i++){
            lef+=nums[i];
            if(lef==x){
                i1=i+1;break;
            }
            else if(lef>x)break;
        }

        int i2=INT_MAX;
        long long rig=0;
        for(int i=n-1;i>=0;i--){
            rig+=nums[i];
            if(rig==x){
                i2=n-i;break;
            }
            else if(rig>x)break;
        }

        int ans=min(i1,i2);
        // cout<<ans;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>x)return (ans==INT_MAX)?-1:ans;
            if(sum==x)return min(i+1,ans);
            auto it=lower_bound(vec.begin(),vec.end(),x-sum);
            int ind=it-vec.begin();
            // cout<<ind<<endl;
            if(ind<vec.size() and vec[ind]==x-sum){
                ans=min(ans,i+1+ind+1);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};