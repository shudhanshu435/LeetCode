class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mp[c+i-j].push_back(mat[i][j]);
            }
        }
        for(auto &i:mp){
            sort(i.second.rbegin(),i.second.rend());
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j]=mp[c+i-j].back();
                mp[c+i-j].pop_back();
            }
        }
        return mat;
    }
};