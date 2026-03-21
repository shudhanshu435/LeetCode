class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i=x,j=x+k-1;
        while(i<j){
            int c=y;
            while(c<y+k){
                swap(grid[i][c],grid[j][c]);
                c++;
            }
            i++;
            j--;
        }
        return grid;
    }
};