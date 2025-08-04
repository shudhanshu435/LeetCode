class Solution {
public:
    vector<vector<char>> rotateMatrix(vector<vector<char>>& matrix) {
        int m = matrix.size();        // rows
        int n = matrix[0].size();     // cols

        vector<vector<char>> rotated(n, vector<char>(m));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][m - 1 - i] = matrix[i][j];
            }
        }

        return rotated;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        for(int i=0;i<n;i++){
            int x=m-1,y=m-1;
            while(x>=0){
                if(boxGrid[i][x]=='#'){
                    boxGrid[i][y]='#';
                    if(y!=x)boxGrid[i][x]='.';
                    y--;
                }
                else if(boxGrid[i][x]=='*')y=x-1;
                x--;
            }
        }
        // for(auto i:boxGrid){
        //     for(auto v:i)cout<<v<<" ";
        //     cout<<endl;
        // }
        vector<vector<char>>v=rotateMatrix(boxGrid);
        return v;
    }
};