class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>vec;
        vector<int>vce,res;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vce.push_back(grid[i][j]);
                
            }
        }
        k=k%vce.size();
        int m=0,cnt=0;
        rotate(vce.begin(), vce.begin()+(vce.size()-k), vce.end());
        
            for(int j=0;j<vce.size();j++){
                res.push_back(vce[m]);
                m++;
                cnt++;
                if(cnt==grid[0].size()){
                    vec.push_back(res);
                    res.clear();
                    cnt=0;
                }
            }
          
       
        return vec;
        
    }
};