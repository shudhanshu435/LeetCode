class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,-1));
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(auto i:dir){
                int nx=x+i.first;
                int ny=y+i.second;

                if(nx>=0 and nx<n and ny>=0 and ny<m and ans[nx][ny]==-1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};