class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%p;
        }
        sum=sum%p;
        if(sum==0)return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int cc=0,mini=n;
        for(int i=0;i<n;i++){
            cc=(cc+nums[i])%p;
            int need=(cc-sum+p)%p;
            if(mp.find(need)!=mp.end()){
                mini=min(mini,i-mp[need]);
            }
            mp[cc]=i;
        }
        return mini==n?-1:mini;
    }
};