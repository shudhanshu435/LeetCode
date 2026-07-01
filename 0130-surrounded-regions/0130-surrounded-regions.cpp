class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][n-1]=='O')q.push({i,n-1});
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')q.push({0,i});
            if(board[m-1][i]=='O')q.push({m-1,i});
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            vis[i][j]=1;
            q.pop();
            if(i-1>=0 and board[i-1][j]=='O' and !vis[i-1][j]){
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            if(i+1<m and board[i+1][j]=='O' and !vis[i+1][j]){
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
            if(j-1>=0 and board[i][j-1]=='O' and !vis[i][j-1]){
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
            if(j+1<n and board[i][j+1]=='O' and !vis[i][j+1]){
                vis[i][j+1]=1;
                q.push({i,j+1});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j])board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};