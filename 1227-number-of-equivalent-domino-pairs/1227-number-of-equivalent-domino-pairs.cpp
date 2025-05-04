class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        map<pair<int,int>,int>mp;
        for(int i=0;i<d.size();i++){
            mp[{min(d[i][0],d[i][1]),max(d[i][0],d[i][1])}]++;
        }
        int ans=0;
        for(auto i:mp){
            ans+=((i.second)*(i.second-1)/2);
        }
        return ans;
    }
};