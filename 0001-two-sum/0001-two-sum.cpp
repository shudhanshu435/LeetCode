class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int a,b;
        if(target%2==0 and mp[target/2].size()>1)return {mp[target/2][0],mp[target/2][1]};
        for(int i=0;i<n;i++){
            if(target/2!=nums[i] and mp.find(target-nums[i])!=mp.end()){
                a=i,b=mp[target-nums[i]][0];break;
            }
        }
        return {a,b};
    }
};