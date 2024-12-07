class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int one=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)one++;
                else if(grid[i][j]==2 )q.push(make_pair(i,j));
            }
        }
        if(one==0)return 0;
        int newone=0,min=0;
        while(!q.empty()){
            int k=q.size();
            min++;
            while(k--){
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i+1<m and grid[i+1][j]==1){newone++;grid[i+1][j]=2;q.push(make_pair(i+1,j));}
                if(j+1<n and grid[i][j+1]==1){newone++;grid[i][j+1]=2;q.push(make_pair(i,j+1));}
                if(i-1>=0 and grid[i-1][j]==1){newone++;grid[i-1][j]=2;q.push(make_pair(i-1,j));}
                if(j-1>=0 and grid[i][j-1]==1){newone++;grid[i][j-1]=2;q.push(make_pair(i,j-1));}
                if(one==newone)return min;
            }
        }
        return -1;
        
    }
};