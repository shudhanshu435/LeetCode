class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        long long sum=0;
        long long ans=0;
        int i=0;
        for(;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        if(mp.size()==k)ans=max(ans,sum);
        int ini=0;
        for(;i<n;i++){
            mp[nums[i]]++;
            mp[nums[ini]]--;
            sum+=nums[i]-nums[ini];
            if(mp[nums[ini]]==0)mp.erase(nums[ini]);
            if(mp.size()==k)ans=max(ans,sum);
            ini++;
        }

        return ans;
    }
};