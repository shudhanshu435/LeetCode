class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            mp[pq.top()]+=1;
            pq.pop();
        }
        vector<int>ans;
        for(auto i:nums){
            if(mp[i]){
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;

    }
};