class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOp) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(auto &i:nums)mp[i]++;
        int ans=0;
        
        for(int i=1;i<=nums[nums.size()-1]+k;i++){
            int bef=i-k;
            int aft=i+k;
            int it=lower_bound(nums.begin(),nums.end(),bef)-nums.begin();
            int ut=upper_bound(nums.begin(),nums.end(),aft)-nums.begin()-1;
            int num=ut-it+1;
            int fre=num-mp[i];
            ans=max(ans,mp[i]+min(numOp,fre));
        }
        return ans;
    }
};