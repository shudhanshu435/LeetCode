class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i<j)swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto &i:matrix){
            reverse(i.begin(),i.end());
        }
    }
};