class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        set<pair<int,int>>p;
        vector<int>col;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=grid[j][i];
            }
            col.push_back(sum);
        }
        // for(auto i:col)cout<<i<<" ";
        // cout<<endl<<endl;
        for(int i=0;i<m;i++){
            int sum = accumulate(grid[i].begin(),grid[i].end(),0);
            if(sum>1){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1)p.insert({i,j});
                }
            }
        }
        // for(auto i:p){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(col[i]>1){
                for(int j=0;j<m;j++){
                    // cout<<i<<" "<<j<<" "<<grid[j][i]<<endl;
                    if(grid[j][i]==1)p.insert({j,i});
                }
            }
        }
        // for(auto i:p){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        return p.size();
    }
};