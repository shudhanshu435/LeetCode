class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int rep=-1;
        long long sum=0;
        for(auto i: grid){
            for(auto ii:i){
                mp[ii]++;
                sum+=ii;
                if(mp[ii]==2){
                    rep=ii;
                }
            }
        }
        sum-=rep;
        int n=grid.size();
        n*=n;
        int miss=(n*(n+1)/2)-sum;
        return {rep,miss};
        
    }
};