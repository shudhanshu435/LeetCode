class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0];
        int cnt=0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==a || edges[i][1]==a)cnt++;
        }
        if(cnt==edges.size())return a;
        return edges[0][1];
    }
};