class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long mat=1;
        int m=grid.size();
        int n=grid[0].size();
        /*
            1 2 3 4 5
            2 3 4 5 1
            2 3 1 2 3
        */
        vector<vector<int>>pre(m,vector<int>(n,1));
        vector<vector<int>>suf(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            pre[i][0]=grid[i][0];
            for(int j=1;j<n;j++){
                pre[i][j]=(grid[i][j]*1ll*pre[i][j-1])%12345;
            }
        }
        for(int i=0;i<m;i++){
            suf[i][n-1]=grid[i][n-1];
            for(int j=n-2;j>=0;j--){
                suf[i][j]=(grid[i][j]*1ll*suf[i][j+1])%12345;
            }
        }
        vector<int>lpre(m);
        lpre[0]=pre[0][n-1];
        for(int i=1;i<m;i++){
            lpre[i]=(pre[i][n-1]*1ll*lpre[i-1])%12345;
        }

        vector<int>lsuf(m);
        lsuf[m-1]=pre[m-1][n-1];
        for(int i=m-2;i>=0;i--){
            lsuf[i]=(pre[i][n-1]*1ll*lsuf[i+1])%12345;
        }

        // for(auto i:lpre)cout<<i<<endl;
        // for(auto i:lsuf)cout<<i<<endl;

        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int l=1,r=1,d=1,u=1;
                if(j-1>=0)l=pre[i][j-1];
                if(j+1<n)r=suf[i][j+1];
                if(i-1>=0)u=lpre[i-1];
                if(i+1<m)d=lsuf[i+1];
                // cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
                ans[i][j]=(l*1ll*r*1ll*d*1ll*u)%12345;
            }
        }

        return ans;
    }
};