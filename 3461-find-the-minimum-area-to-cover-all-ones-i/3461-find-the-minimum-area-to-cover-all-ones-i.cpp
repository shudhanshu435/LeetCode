class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int u=-1,d=-1,l=-1,r=-1;
        // from up
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    u=i;break;
                }
            }
            if(u!=-1)break;
        }
        // from down
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    d=i;break;
                }
            }
            if(d!=-1)break;
        }
        // from left
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    l=i;break;
                }
            }
            if(l!=-1)break;
        }
        // from right
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    r=i;break;
                }
            }
            if(r!=-1)break;
        }

        return (d-u+1)*(r-l+1);
    }
};