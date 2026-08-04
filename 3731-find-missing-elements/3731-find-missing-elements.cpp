class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i:nums){
            mp[i]++;
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        for(;mini<=maxi;mini++){
            if(mp[mini]==0)ans.push_back(mini);
        }
        return ans;
    }
};