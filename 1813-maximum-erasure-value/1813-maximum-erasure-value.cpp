class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // so we have to basically max sum subarray of unique elements.
        unordered_map<int,int>mp;
        int n=nums.size();
        int j=0;
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            sum+=nums[i];
            // cout<<sum<<" ";
            if(mp[nums[i]]!=2)ans=max(ans,sum);
            while(mp[nums[i]]==2){
                sum-=nums[j];
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};