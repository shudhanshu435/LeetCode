class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==target){cnt++;break;}
            }
            if(cnt!=0)break;
        }
        if(cnt!=0)return 1;
        else return 0;
    }
};