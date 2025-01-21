class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long p = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long ans=LLONG_MAX;
        int n=grid[0].size();
        long long s=0;
        for(int i=0;i<n;i++){
            p-=grid[0][i];
            ans=min(ans,max(p,s));
            s+=grid[1][i];
        }
        return ans;
    }
}; 