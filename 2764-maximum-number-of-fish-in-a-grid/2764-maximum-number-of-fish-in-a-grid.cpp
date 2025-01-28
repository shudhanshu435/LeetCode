class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    int sum=0;
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        sum+=grid[r][c];
                        grid[r][c]=0;
                        q.pop();

                        if(r-1>=0 and grid[r-1][c]!=0)q.push({r-1,c});
                        if(r+1<m and grid[r+1][c]!=0)q.push({r+1,c});
                        if(c-1>=0 and grid[r][c-1]!=0)q.push({r,c-1});
                        if(c+1<n and grid[r][c+1]!=0)q.push({r,c+1});
                    }
                    ans=max(ans,sum);
                }
            }
         }
         return ans;
    }
};