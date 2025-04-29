class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int>mp;
        int s=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[maxi]==k){
                ans+=n-i;
                mp[nums[s]]--;
                s++;
            }
        }
        return ans;
    }
};