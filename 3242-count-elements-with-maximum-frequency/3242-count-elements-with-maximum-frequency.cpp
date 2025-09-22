class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        int ans=0;
        for(auto &[a,b]:mp){
            if(b==maxi)ans+=b;
        }
        return ans;
    }
};