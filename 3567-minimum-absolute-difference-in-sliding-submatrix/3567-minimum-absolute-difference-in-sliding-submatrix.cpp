class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        // 1 -2 3 
        // 2  3 5
        int m=grid.size();
        int n=grid[0].size();
        if(k==1){
            vector<vector<int>>res(m,vector<int>(n,0));
            return res;
        }
        vector<vector<int>>res;
        for(int i=0;i<=m-k;i++){
            vector<int>vv;
            for(int j=0;j<=n-k;j++){
                int ans=INT_MAX;
                set<int>v;
                int c=i;
                while(c<i+k){
                    for(int mm=j;mm<j+k;mm++){
                        v.insert(grid[c][mm]);
                    }
                    c++;
                }
                // for(auto i:v)cout<<i<<" ";
                // cout<<endl;
                if(v.size()==1){
                    vv.push_back(0);
                    continue;
                }
                auto it = v.begin();
                auto prev = it;
                it++;

                while(it != v.end()){
                    ans = min(ans, *it - *prev);
                    prev = it;
                    it++;
                }
                vv.push_back(ans);
            }
            res.push_back(vv);
        }
        return res;
    }
};
