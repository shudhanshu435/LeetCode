class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(auto &i:mp){
            if((i.first)&1){
                vector<int>v=i.second;
                for(auto &i:v)ans.push_back(i);
            }
            else{
                vector<int>v=i.second;
                reverse(v.rbegin(),v.rend());
                for(auto &i:v)ans.push_back(i);
            }
        }
        return ans;
    }
};