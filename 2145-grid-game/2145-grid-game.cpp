class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long>p(n);
        vector<long long>s(n);
        p[0]=grid[0][0];
        for(int i=1;i<n;i++){
            p[i]=grid[0][i]+p[i-1];
        }
        s[n-1]=grid[1][n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=grid[1][i]+s[i+1];
        }
        long long ans=5*1ll*INT_MAX;
        for(int i=0;i<n;i++){
            long long maxii=max(s[0]-s[i],p[n-1]-p[i]);
            ans=min(ans,maxii);
        }
        return ans;
    }
}; 