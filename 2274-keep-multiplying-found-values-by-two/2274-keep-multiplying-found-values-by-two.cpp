class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mp;
        for(auto &i:nums)mp[i]++;
        while(1){
            if(mp[original]==0)return original;
            original*=2;
        }
    }
};