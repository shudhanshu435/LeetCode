class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
         cin.tie(0) -> sync_with_stdio(false);
        set<pair<int,pair<int,int>>> st;
        int m = grid.size(), n = grid[0].size(),cnt= 0,mxel = 0;
        vector<int> ans,mx(m*n+1);
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        st.insert({grid[0][0], {0,0}});
        vis[0][0] = true;
        mx[0] = 0;
        while(!st.empty()){
            auto tp =  *st.begin();
            st.erase(st.begin());
            mxel = max(mxel,tp.first);
            cnt++;
            mx[cnt] = mxel;
            int ni = tp.second.first - 1, nj = tp.second.second;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
            ni = tp.second.first + 1;nj = tp.second.second;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
            ni = tp.second.first;nj = tp.second.second - 1;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
            ni = tp.second.first;nj = tp.second.second + 1;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
        }
        for(auto i : queries){
            int s = 0, e = m*n,anss = 0;
            while(s <= e){
                int md = s + (e-s)/2;
                if([&](){
                    return mx[md] < i;
                }()){
                    anss = md;
                    s = md + 1;
                }else{
                    e = md - 1;
                }
            }
            ans.push_back(anss);
        }
        return ans;
    }
};