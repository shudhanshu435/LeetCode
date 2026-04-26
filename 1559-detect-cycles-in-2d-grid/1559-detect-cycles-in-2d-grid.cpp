class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(vis[i][j]) continue;

                char ch = grid[i][j];

                queue<pair<int,int>> q;
                map<pair<int,int>,pair<int,int>> mp;

                q.push({i,j});
                vis[i][j]=true;

                mp[{i,j}] = {-1,-1};

                while(!q.empty()){

                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();

                    // down
                    if(x+1<n and grid[x+1][y]==ch){

                        if(!vis[x+1][y]){
                            vis[x+1][y]=true;
                            mp[{x+1,y}]={x,y};
                            q.push({x+1,y});
                        }
                        else if(mp[{x,y}]!=make_pair(x+1,y)){
                            return 1;
                        }
                    }

                    // up
                    if(x-1>=0 and grid[x-1][y]==ch){

                        if(!vis[x-1][y]){
                            vis[x-1][y]=true;
                            mp[{x-1,y}]={x,y};
                            q.push({x-1,y});
                        }
                        else if(mp[{x,y}]!=make_pair(x-1,y)){
                            return 1;
                        }
                    }

                    // right
                    if(y+1<m and grid[x][y+1]==ch){

                        if(!vis[x][y+1]){
                            vis[x][y+1]=true;
                            mp[{x,y+1}]={x,y};
                            q.push({x,y+1});
                        }
                        else if(mp[{x,y}]!=make_pair(x,y+1)){
                            return 1;
                        }
                    }

                    // left
                    if(y-1>=0 and grid[x][y-1]==ch){

                        if(!vis[x][y-1]){
                            vis[x][y-1]=true;
                            mp[{x,y-1}]={x,y};
                            q.push({x,y-1});
                        }
                        else if(mp[{x,y}]!=make_pair(x,y-1)){
                            return 1;
                        }
                    }

                }
            }
        }

        return 0;
    }
};