class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    ans++;
                }
                while(!q.empty()){
                    int i=q.front().first;
                    int j=q.front().second;
                    q.pop();
                    if(i-1>=0 and grid[i-1][j]=='1'){
                        q.push({i-1,j});
                        grid[i-1][j]='0';
                    }
                    if(i+1<n and grid[i+1][j]=='1'){
                        q.push({i+1,j});
                        grid[i+1][j]='0';
                    }
                    if(j-1>=0 and grid[i][j-1]=='1'){
                        q.push({i,j-1});
                        grid[i][j-1]='0';
                    }
                    if(j+1<m and grid[i][j+1]=='1'){
                        q.push({i,j+1});
                        grid[i][j+1]='0';
                    }
                }
                
            }
        }
        return ans;
    }
};