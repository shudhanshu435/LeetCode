class Solution {
public:
      
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;
        vector<int>res;
        
        res.push_back(1);
        vec.push_back(res);
        if(numRows==1)return vec;
        
        res.push_back(1);
        vec.push_back(res);
        for(int i=2;i<numRows;i++){
            res.clear();
            res.push_back(1);
            for(int j=1;j<i;j++){
                res.push_back(vec[i-1][j-1]+vec[i-1][j]);
            }
            res.push_back(1);
            vec.push_back(res);
        }
        return vec;
    }
};