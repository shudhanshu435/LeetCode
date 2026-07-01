class Solution {
public:
    bool pos(int mid, vector<vector<int>>&dist){
        int n=dist.size();
        queue<pair<int,int>>q;
        q.push({0,0});
        if(dist[0][0]<mid or dist[n-1][n-1]<mid)return 0;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        vis[0][0]=1;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if(i==n-1 and j==n-1)return 1;
            q.pop();
            if(i-1>=0 and dist[i-1][j]>=mid and !vis[i-1][j]){
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(i+1<n and dist[i+1][j]>=mid and !vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(j-1>=0 and dist[i][j-1]>=mid and !vis[i][j-1]){
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
            if(j+1<n and dist[i][j+1]>=mid and !vis[i][j+1]){
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int l=1,r=n-1+n-1;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 and dist[i-1][j]>dist[i][j]+1){
                dist[i-1][j]=dist[i][j]+1;
                q.push({i-1,j});
            }
            if(i+1<n and dist[i+1][j]>dist[i][j]+1){
                dist[i+1][j]=dist[i][j]+1;
                q.push({i+1,j});
            }
            if(j-1>=0 and dist[i][j-1]>dist[i][j]+1){
                dist[i][j-1]=dist[i][j]+1;
                q.push({i,j-1});
            }
            if(j+1<n and dist[i][j+1]>dist[i][j]+1){
                dist[i][j+1]=dist[i][j]+1;
                q.push({i,j+1});
            }
        }

        // for(auto i:dist){
        //     for(auto j:i)cout<<j<<" ";
        //     cout<<endl;
        // }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(mid,dist)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }


        return ans;

    }
};