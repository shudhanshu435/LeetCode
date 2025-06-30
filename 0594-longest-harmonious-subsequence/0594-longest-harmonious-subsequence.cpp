class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        vector<int>vec;
        for(auto i:mp)vec.push_back(i.first);
        int ans=0;
        for(int i=1;i<vec.size();i++){
            if(vec[i]-vec[i-1]==1){
                ans=max(ans,mp[vec[i]]+mp[vec[i-1]]);
            }
        }
        return ans;
    }
};