class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[i][j]);
            }
            ans+=maxi;
            maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }
            ans+=maxi;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])ans++;
            }
        }
        return ans;
    }
};