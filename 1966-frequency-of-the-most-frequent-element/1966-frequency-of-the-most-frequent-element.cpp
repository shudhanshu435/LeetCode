class Solution {
public:
    long long binS(int i, int k, vector<long long>&pref, int num){
        long long l=0,r=i,ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long diff;
            if(mid==0)diff=pref[i];
            else diff=pref[i]-pref[mid-1];
            long long s=(i-mid+1)*1ll*num;
            if(s-diff<=k){
                ans=i-mid+1;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long bs=binS(i,k,pref,nums[i]);
            ans=max(ans,bs);
        }
        return (int)ans;
    }
};