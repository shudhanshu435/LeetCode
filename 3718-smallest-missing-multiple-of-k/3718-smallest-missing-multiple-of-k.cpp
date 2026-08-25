class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int x=k;
        while(1){
            if(mp[x]==0)return x;
            x+=k;
        }
        return 0;
    }
};