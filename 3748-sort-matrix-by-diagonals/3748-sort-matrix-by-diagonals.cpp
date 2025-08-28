class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &[a,b]:mp){
            if(a>=0)sort(b.begin(),b.end());
            else sort(b.rbegin(),b.rend());
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};