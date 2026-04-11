class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &[a,b]:mp){
            for(int j=0;j<(int)b.size()-2;j++){
                ans=min(ans, abs(b[j]-b[j+1])+abs(b[j+1]-b[j+2])+abs(b[j]-b[j+2]));
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};