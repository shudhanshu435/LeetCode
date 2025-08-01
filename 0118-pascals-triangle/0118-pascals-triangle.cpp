class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vv;
        vector<int>vvv;
        vv.push_back({1});
        while(--numRows){
            vector<int>v;
            v.push_back(1);
            for(int i=1;i<vvv.size();i++){
                v.push_back(vvv[i-1]+vvv[i]);
            }
            v.push_back(1);
            vvv=v;
            vv.push_back(v);
        }
        return vv;
    }
};