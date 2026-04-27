class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 and n==1)return 1;
        int x=m-1,y=n-1;
        map<pair<int,int>,bool>mp;
        mp[{x,y}]=1;
        while(x>=0 and x<m and y>=0 and y<n){
            if(grid[x][y]==1){
                if(y-1>=0 and !mp[{x,y-1}]){
                    if(grid[x][y-1]==2 or grid[x][y-1]==3 or grid[x][y-1]==5)return 0;
                    mp[{x,y-1}]=1;
                    y=y-1;
                }
                else if(y+1<n and !mp[{x,y+1}]){
                    if(grid[x][y+1]==2 or grid[x][y+1]==4 or grid[x][y+1]==6)return 0;
                    mp[{x,y+1}]=1;
                    y=y+1;
                }
                else return 0;
            }
            else if(grid[x][y]==2){
                // cout<<"sdfg";
                if(x-1>=0 and !mp[{x-1,y}]){
                    if(x-1==0 and y==0)return 1;
                    if(grid[x-1][y]==1 or grid[x-1][y]==5 or grid[x-1][y]==6)return 0;
                    mp[{x-1,y}]=1;
                    x=x-1;
                }
                else if(x+1<m and !mp[{x+1,y}]){
                    if(x+1==0 and y==0)return 1;
                    if(grid[x+1][y]==1 or grid[x+1][y]==3 or grid[x+1][y]==4)return 0;
                    mp[{x+1,y}]=1;
                    x=x+1;
                }
                else return 0;
            }
            else if(grid[x][y]==3){
                if(y-1>=0 and !mp[{x,y-1}]){
                    if(x==0 and y-1==0)return 1;
                    if(grid[x][y-1]==2 or grid[x][y-1]==3 or grid[x][y-1]==5)return 0;
                    mp[{x,y-1}]=1;
                    y=y-1;
                }
                else if(x+1<m and !mp[{x+1,y}]){
                    if(x+1==0 and y==0)return 1;
                    if(grid[x+1][y]==1 or grid[x+1][y]==3 or grid[x+1][y]==4)return 0;
                    mp[{x+1,y}]=1;
                    x=x+1;
                }
                else return 0;
            }
            else if(grid[x][y]==4){
                if(y+1<n and !mp[{x,y+1}]){
                    if(x==0 and y+1==0)return 1;
                    if(grid[x][y+1]==2 or grid[x][y+1]==4 or grid[x][y+1]==6)return 0;
                    mp[{x,y+1}]=1;
                    y=y+1;
                }
                else if(x+1<m and !mp[{x+1,y}]){
                    if(x+1==0 and y==0)return 1;
                    if(grid[x+1][y]==1 or grid[x+1][y]==4 or grid[x+1][y]==3)return 0;
                    mp[{x+1,y}]=1;
                    x=x+1;
                }
                else return 0;
            }
            else if(grid[x][y]==5){
                int t=1,w=1;
                if(x-1>=0 and !mp[{x-1,y}]){
                    if(x-1==0 and y==0)return 1;
                    if(grid[x-1][y]==1 or grid[x-1][y]==5 or grid[x-1][y]==6)t= 0;
                    mp[{x-1,y}]=1;
                    x=x-1;
                }
                if(y-1>=0 and !mp[{x,y-1}]){
                    if(x==0 and y-1==0)return 1;
                    if(grid[x][y-1]==2 or grid[x][y-1]==3 or grid[x][y-1]==5)w= 0;
                    mp[{x,y-1}]=1;
                    y=y-1;
                }
                else return 0;
                if(t==0 and w==0)return 0;
            }
            else{
                int t=1,w=1;
                if(x-1>=0 and !mp[{x-1,y}]){
                    if(x-1==0 and y==0)return 1;
                    if(grid[x-1][y]==1 or grid[x-1][y]==5 or grid[x-1][y]==6)return 0;
                    mp[{x-1,y}]=1;
                    x=x-1;
                }
                else if(y+1<n and !mp[{x,y+1}]){
                    if(x==0 and y+1==0)return 1;
                    if(grid[x][y+1]==2 or grid[x][y+1]==4 or grid[x][y+1]==6)return 0;
                    mp[{x,y+1}]=1;
                    y=y+1;
                }
                else return 0;
                if(t==0 and w==0)return 0;
            }
            // cout<<x<<" "<<y<<endl;
            if(x==y and x==0)return 1;
        }
        return 0;
    }
};