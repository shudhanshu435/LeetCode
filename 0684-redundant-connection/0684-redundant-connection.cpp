class Solution {
    class DSU{
        vector<int> parent;
        vector<int> sz;
        public:
        DSU(int n){
            for(int i=0; i<=n; i++){
                parent.push_back(i);
                sz.push_back(1);
            }
        }
        int find(int u){
            if(parent[u] != u){
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }
        void unionBySize(int u, int v){
            int pu = find(u);
            int pv = find(v);

            if(pu!=pv){
                if(sz[pu]>= sz[pv]){
                    parent[pv] = pu;
                    sz[pu]+=sz[pv];
                }
                else{
                    parent[pu] = pv;
                    sz[pv]+=sz[pu];
                }
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int> ans;
        for(int i=0; i<n; i++){
            int x = edges[i][0];
            int y = edges[i][1];

            int px = dsu.find(x);
            int py = dsu.find(y);

            if(px == py){
                ans = edges[i];
            }
            else{
                dsu.unionBySize(px,py);
            }
        }
        return ans;
    }
};