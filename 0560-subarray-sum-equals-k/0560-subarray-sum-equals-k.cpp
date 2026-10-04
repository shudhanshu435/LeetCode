class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cn=0,s=0;
        mp[0]=1;
        for(auto i:nums){
            s+=i;
            if(mp[s-k])cn+=mp[s-k];
            mp[s]++;
        }
        return cn;
    }
};