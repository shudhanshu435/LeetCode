class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];
    ll solve(bool pt, int ph, int col, vector<vector<int>>& grid, vector<vector<ll>>&colPrefSum){
        if(col==n)return 0;
        ll res=0;
        if(t[pt][ph][col]!=-1)return t[pt][ph][col];
        for(int h=0;h<=n;h++){
            ll ps=0;
            ll cs=0;
            if(!pt and col-1>=0 and h>ph){
                ps+=colPrefSum[h][col]-colPrefSum[ph][col];
            }

            if(h<ph){
                cs+=colPrefSum[ph][col+1]-colPrefSum[h][col+1];
            }

            ll taken=cs+ps+solve(true,h,col+1,grid,colPrefSum);
            ll nottaken=ps+solve(false,h,col+1,grid,colPrefSum);

            res=max({res,taken,nottaken});
        }
        return t[pt][ph][col]=res;
    }
    long long maximumScore(vector<vector<int>>& grid) {
        n=grid.size();
        memset(t,-1,sizeof(t));
        vector<vector<ll>>colPrefSum(n+1, vector<ll>(n+1,0));
        for(int col=1;col<=n;col++){
            for(int row=1;row<=n;row++){
                colPrefSum[row][col]=colPrefSum[row-1][col]+grid[row-1][col-1];
            }
        }

        return solve(false,0,0,grid,colPrefSum);
    }
};