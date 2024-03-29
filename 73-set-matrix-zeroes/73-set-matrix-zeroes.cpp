class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> s,ss;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    s.insert(i);
                    ss.insert(j);
                }
            }
        }
        vector<int>vec,tec;
        set<int>::iterator itr;
        for (itr = s.begin(); 
             itr != s.end(); itr++) 
        {
            vec.push_back(*itr);
        }
        set<int>::iterator ir;
        for (ir = ss.begin(); 
             ir != ss.end(); ir++) 
        {
            tec.push_back(*ir);
        }
  
        for (int k = 0; k < vec.size(); k++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (i == vec[k])
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        for (int k = 0; k < tec.size(); k++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (j == tec[k])
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};