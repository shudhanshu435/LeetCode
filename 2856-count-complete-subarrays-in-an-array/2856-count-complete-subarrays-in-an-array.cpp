class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        // cout<<mp.size()<<endl;
        int ans=0,cnt=0,j;
        for(int i=0;i<n;i++){
            cnt=0;
            for(j=n-1;j>=i;j--){
                cnt++;
                if(mp[nums[j]]==1)break;
                mp[nums[j]]--;
            }
            ans+=cnt;
            for(;j<n-1;j++)mp[nums[j+1]]++;
            mp[nums[i]]--;
            if(mp[nums[i]]==0)break;
        }

        return ans;
    }
};