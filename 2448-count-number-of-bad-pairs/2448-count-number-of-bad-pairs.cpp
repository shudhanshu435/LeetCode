class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[(nums[i]-i)]++;
        }
        long long ans=0;
        for(auto i:mp){
            if(i.second>=2){
                ans+=(i.second)*1ll*(i.second-1)/2;
            }
        }
        ans=n*1ll*(n-1)/2 - ans;
        return ans;
    }
};