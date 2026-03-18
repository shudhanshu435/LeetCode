class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>rows(m,vector<int>(n,0));
        vector<vector<int>>cols(m,vector<int>(n,0));
        vector<vector<int>>ans(m,vector<int>(n,0));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0)rows[i][j]=rows[i][j-1]+grid[i][j];
                else rows[i][j]=grid[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0)cols[j][i]=cols[j-1][i]+grid[j][i];
                else cols[j][i]=grid[j][i];
            }
        }

        int anss=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long long val=rows[i][j]+cols[i][j]-grid[i][j];
                if(i-1>=0 and j-1>=0)val+=ans[i-1][j-1];
                if(val<=k)anss++;
                ans[i][j]=val;
            }
        }

        return anss;

    }
};