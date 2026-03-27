class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        if(k==0)return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][(j+k)%m]!=mat[i][j])return 0;
            }
        }
        return 1;
    }
};