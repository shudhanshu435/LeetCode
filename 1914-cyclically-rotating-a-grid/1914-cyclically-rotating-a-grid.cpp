class Solution {
public:
    void rotation(vector<vector<int>>& grid, int i,int k, int m, int n){

        vector<int> ring;
            int top=i, bottom=m-1-i;
            int left=i, right=n-1-i;

            for(int col=left; col<=right; col++) ring.push_back(grid[top][col]); // top row ->
            for(int row=top+1; row<=bottom; row++) ring.push_back(grid[row][right]); // right col |
            for(int col=right-1; col>=left; col--) ring.push_back(grid[bottom][col]); // bottom row <-
            for(int row=bottom-1; row>top; row--) ring.push_back(grid[row][left]);
            k = k % ring.size();
            std::rotate(ring.begin(), ring.begin()+k, ring.end());

        int index=0;
            for(int col=left; col<=right; col++) grid[top][col]=ring[index++]; // top row ->
            for(int row=top+1; row<=bottom; row++) grid[row][right]=ring[index++]; // right col |
            for(int col=right-1; col>=left; col--) grid[bottom][col]=ring[index++]; // bottom row <-
            for(int row=bottom-1; row>top; row--)grid[row][left]=ring[index++];


    }




    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0; i<min(m,n)/2;i++) {
            rotation( grid,i,k,m,n);
        }

        return grid;
    }
};