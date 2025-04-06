class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>>mp;
        mp[nums[0]].push_back(nums[0]);
        for(int i=1;i<n;i++){
            int val=0;
            int m=0;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(mp[nums[j]].size()>m){
                        val=nums[j];
                        m=mp[val].size();
                    }
                }
            }
            mp[nums[i]]=mp[val];
            mp[nums[i]].push_back(nums[i]);
        }
        //[3 4 8 16]
        vector<int>v;
        int s=0;
        for(auto i:mp){
            if(i.second.size()>s){
                s=i.second.size();
                v=i.second;
            }
        }
        return v;
        
    }
};