class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<long long,long long>>>vec(m,vector<pair<long long,long long>>(n));
        vec[0][0].first=grid[0][0];
        vec[0][0].second=grid[0][0];
        for(int i=1;i<m;i++){
            vec[i][0].first=vec[i-1][0].first*grid[i][0];
            vec[i][0].second=vec[i-1][0].second*grid[i][0];
        }
        for(int i=1;i<n;i++){
            vec[0][i].first=vec[0][i-1].first*grid[0][i];
            vec[0][i].second=vec[0][i-1].second*grid[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long mini=min({vec[i][j-1].first,vec[i][j-1].second,vec[i-1][j].first,vec[i-1][j].second});
                long long maxi=max({vec[i][j-1].first,vec[i][j-1].second,vec[i-1][j].first,vec[i-1][j].second});
                vec[i][j].first=min(mini*grid[i][j],maxi*grid[i][j]);
                vec[i][j].second=max(mini*grid[i][j],maxi*grid[i][j]);
            }
        }
        int ans=max(vec[m-1][n-1].first,vec[m-1][n-1].second)%1000000007;
        if(ans<0)return -1;
        return ans;

    }
};