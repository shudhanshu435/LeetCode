class Solution {
public:
    bool exist(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = true;
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == n - 1) return true;

            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !vis[nx][ny] && mat[nx][ny] == 0) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
    bool pos(vector<vector<int>>&mat,int r, int c, int k){
        vector<vector<int>>vv(r,vector<int>(c,0));
        int i=0;
        while(i<k){
            vv[mat[i][0]-1][mat[i][1]-1]=1;
            i++;
        }
        // for(auto i:vv){
        //     for(auto ii:i)cout<<ii<<" ";
        //     cout<<endl;
        // }
        if(exist(vv))return 1;
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int i=1,j=cells.size();
        int ans=0;
        while(i<=j){
            long long mid=i+(j-i)/2;
            // cout<<i<<" "<<j<<" "<<mid<<endl;
            if(pos(cells,row,col,mid)){
                ans=mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return ans;
    }
};