class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector<vector<int>>directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        //base
        if(grid[0][1]>1 and grid[1][0]>1)return -1;
        
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<vector<int>>result(m, vector<int>(n,INT_MAX));
        pq.push({0, {0,0}});
        result[0][0]=0;
        vector<vector<int>>visited(m, vector<int>(n, false));

        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==m-1 and col==n-1)return result[m-1][n-1];
            if(visited[row][col]==true)continue;
            visited[row][col]=true;
            for(auto& dir:directions){
                int i= row+dir[0];
                int j= col+dir[1];
                if(i<0 or i>=m or j<0 or j>=n){
                    continue;
                }
                if(grid[i][j]<=time+1){
                    pq.push({time+1, {i,j}});
                    result[i][j]=time+1;
                }
                else if((grid[i][j]-time)%2==0){
                    pq.push({grid[i][j]+1, {i,j}});
                    result[i][j]=grid[i][j]+1;
                }
                else{
                    pq.push({grid[i][j], {i,j}});
                    result[i][j]=grid[i][j];
                }

            }
        }
        return result[m-1][n-1];
    }
};