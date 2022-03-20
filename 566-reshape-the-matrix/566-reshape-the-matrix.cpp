class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> vec;
        vector<int> test;
        int len = 0;
        if(r*c!=mat.size()*mat[0].size())return mat;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                test.push_back(mat[i][j]);
                len++;
                if (len == c)
                {
                    vec.push_back(test);
                    test.clear();
                    len = 0;
                }
            }
        }
        return vec;
    }
};