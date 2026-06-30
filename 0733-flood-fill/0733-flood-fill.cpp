class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        q.push({sr,sc});
        if(grid[sr][sc]==color)return grid;
        int v=grid[sr][sc];
        grid[sr][sc]=color;

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 and grid[i-1][j]==v){
                q.push({i-1,j});
                grid[i-1][j]=color;
            }
            if(i+1<n and grid[i+1][j]==v){
                q.push({i+1,j});
                grid[i+1][j]=color;
            }
            if(j-1>=0 and grid[i][j-1]==v){
                q.push({i,j-1});
                grid[i][j-1]=color;
            }
            if(j+1<m and grid[i][j+1]==v){
                q.push({i,j+1});
                grid[i][j+1]=color;
            }
        }

        return grid;
    }
};