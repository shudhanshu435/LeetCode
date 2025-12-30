class Solution {
public:
    bool magic(vector<vector<int>>&v){
        set<int>s;
        for(auto &i:v){
            for(auto &ii:i){
                if(ii>=10 or ii==0)return false;
                s.insert(ii);
            }
        }
        if(s.size()!=9)return false;
        int a=v[0][0]+v[0][1]+v[0][2];
        int b=v[1][0]+v[1][1]+v[1][2];
        int c=v[2][0]+v[2][1]+v[2][2];
        int d=v[0][0]+v[1][0]+v[2][0];
        int e=v[0][1]+v[1][1]+v[2][1];
        int f=v[0][2]+v[1][2]+v[2][2];
        int g=v[0][0]+v[1][1]+v[2][2];
        int h=v[2][0]+v[1][1]+v[0][2];
        return (a==b and b==c and c==d and d==e and e==f and f==g and g==h);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n<3 or m<3)return 0;
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                int k=j;
                vector<int>v1,v2,v3;
                v1.push_back(grid[i][k]);
                v1.push_back(grid[i][k+1]);
                v1.push_back(grid[i][k+2]);
                v2.push_back(grid[i+1][k]);
                v2.push_back(grid[i+1][k+1]);
                v2.push_back(grid[i+1][k+2]);
                v3.push_back(grid[i+2][k]);
                v3.push_back(grid[i+2][k+1]);
                v3.push_back(grid[i+2][k+2]);
                vector<vector<int>>v;
                v.push_back(v1);
                v.push_back(v2);
                v.push_back(v3);
                if(magic(v))cnt++;
            }
        }
        return cnt;
    }
};