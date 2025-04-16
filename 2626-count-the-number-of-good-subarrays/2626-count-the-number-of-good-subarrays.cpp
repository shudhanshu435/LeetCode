class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        long long curr=0, st=0,ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            curr+=mp[nums[i]]-1;
            while(curr>=k){
                ans+=(n-i);
                curr-=mp[nums[st]]-1;
                mp[nums[st]]--;
                st++;
            }
        }
        return ans;
    }
};