class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                    cnt++;
                }
                while(!q.empty()){
                    int i=q.front().first;
                    int j=q.front().second;
                    q.pop();
                    if(i-1>=0 and grid[i-1][j]==1){
                        q.push({i-1,j});
                        grid[i-1][j]=0;
                        cnt++;
                    }
                    if(i+1<n and grid[i+1][j]==1){
                        q.push({i+1,j});
                        grid[i+1][j]=0;
                        cnt++;
                    }
                    if(j-1>=0 and grid[i][j-1]==1){
                        q.push({i,j-1});
                        grid[i][j-1]=0;
                        cnt++;
                    }
                    if(j+1<m and grid[i][j+1]==1){
                        q.push({i,j+1});
                        grid[i][j+1]=0;
                        cnt++;
                    }
                }
                ans=max(ans,cnt);
                
            }
        }
        return ans;
    }
};