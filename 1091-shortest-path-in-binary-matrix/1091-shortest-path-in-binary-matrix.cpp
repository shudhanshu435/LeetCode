class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int cnt=1;
        int n=grid.size();
        
        if(grid[0][0]==1)return -1;
        if(n==1)return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>vis(n,vector<int>(n));
        vis[0][0]=1;
        while(!q.empty()){
            int k=q.size();
            cnt++;
            while(k--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                //Left-Up
                if(i-1>=0 and j-1>=0 and grid[i-1][j-1]==0 and !vis[i-1][j-1]){
                    q.push({i-1,j-1});
                    vis[i-1][j-1]=1;
                    if(i-1==n-1 and j-1==n-1)return cnt;
                }
                //Up
                if(i-1>=0 and grid[i-1][j]==0 and !vis[i-1][j]){
                    q.push({i-1,j});
                    vis[i-1][j]=1;
                    if(i-1==n-1 and j==n-1)return cnt;
                }
                //Up-right
                if(i-1>=0 and j+1<n and grid[i-1][j+1]==0 and !vis[i-1][j+1]){
                    q.push({i-1,j+1});
                    vis[i-1][j+1]=1;
                    if(i-1==n-1 and j+1==n-1)return cnt;
                }
                //right
                if(j+1<n and grid[i][j+1]==0 and !vis[i][j+1]){
                    q.push({i,j+1});
                    vis[i][j+1]=1;
                    if(i==n-1 and j+1==n-1)return cnt;
                }
                //right-down
                if(i+1<n and j+1<n and grid[i+1][j+1]==0 and !vis[i+1][j+1]){
                    q.push({i+1,j+1});
                    vis[i+1][j+1]=1;
                    if(i+1==n-1 and j+1==n-1)return cnt;
                }
                //down
                if(i+1<n and grid[i+1][j]==0 and !vis[i+1][j]){
                    q.push({i+1,j});
                    vis[i+1][j]=1;
                    if(i+1==n-1 and j==n-1)return cnt;
                }
                //left-down
                if(i+1<n and j-1>=0 and grid[i+1][j-1]==0 and !vis[i+1][j-1]){
                    q.push({i+1,j-1});
                    vis[i+1][j-1]=1;
                    if(i+1==n-1 and j-1==n-1)return cnt;
                }
                //left
                if(j-1>=0 and grid[i][j-1]==0 and !vis[i][j-1]){
                    q.push({i,j-1});
                    vis[i][j-1]=1;
                    if(i==n-1 and j-1==n-1)return cnt;
                }
            }
        }
        return -1;
    }
};