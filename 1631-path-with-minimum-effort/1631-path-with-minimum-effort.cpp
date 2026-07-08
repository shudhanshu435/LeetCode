class Solution {
public:
    bool pos(int mid, vector<vector<int>>& hh){
        int n=hh.size();
        int m=hh[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1 and y==m-1)return 1;
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m and abs(hh[nx][ny]-hh[x][y])<=mid and !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& hh) {
        int i=0,j=INT_MIN;
        for(auto ii:hh){
            for(auto jj:ii){
                j=max(jj,j);
            }
        }
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(pos(mid,hh)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};