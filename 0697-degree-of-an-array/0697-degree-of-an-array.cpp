class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            int s=mp[nums[i]].size();
            maxi=max(maxi,s);
        }
        int ans=INT_MAX;
        for(auto i:mp){
            vector<int>v=i.second;
            if(v.size()==maxi){
                ans=min(ans,v.back()-v[0]+1);
            }
        }
        return ans;

    }
};