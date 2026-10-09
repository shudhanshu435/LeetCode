class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vec(n,vector<int>(m,0));
        vec[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            vec[i][0]=vec[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            vec[0][i]=vec[0][i-1]+grid[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                vec[i][j]=grid[i][j]+min(vec[i-1][j],vec[i][j-1]);
            }
        }

        return vec[n-1][m-1];
    }
};