class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j)swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }

        return mat;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int rot=4;
        while(rot--){
            mat=transpose(mat);
            if(mat==target)return 1;
        }
        return 0;
    }
};