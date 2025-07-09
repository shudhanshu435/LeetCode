class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &i:nums)mp[i]++;

        int ans=0;
        if(k==0){
            for(auto &[m,n]:mp)ans+=(n>1);
            return ans;
        }

        set<pair<int,int>>s;
        // cout<<mp.size()<<endl;
        // for(auto &i:mp)cout<<i.first<<" "<<i.second<<" "<<endl;
        for(auto &m:mp){
            int val=m.first;
            if(mp.count(val+k)){
                ans++;
            }

        }
        return ans;
    }
};