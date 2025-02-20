class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,map<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if((i+j)&1){
                    mp[i+j][i]=mat[i][j];
                }
                else{
                    mp[i+j][j]=mat[i][j];
                }
            }
        }
        vector<int>vec;
        for(auto i:mp){
            for(auto j:i.second){
                vec.push_back(j.second);
            }
        }
        return vec;
    }
};