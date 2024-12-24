typedef vector<int> vi;
typedef vector<vi> vvi;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto dia = [](const vvi& edges) {
            int n = edges.size() + 1;
            vvi adj(n);
            for (const auto& e : edges) {
                adj[e[0]].pb(e[1]);
                adj[e[1]].pb(e[0]);
            }
            auto dfs = [&](int s) {
                vi dist(n, -1);
                queue<int> queue;
                queue.push(s);
                dist[s] = 0;
                int fa = s;
                while (!queue.empty()) {
                    int nod = queue.front();
                    queue.pop();
                    for (auto n : adj[nod]) {
                        if (dist[n] == -1) {
                            dist[n] = dist[nod] + 1;
                            queue.push(n);
                            if (dist[n] > dist[fa]) {
                                fa = n;
                            }
                        }
                    }
                }
                return mp(fa, dist[fa]);
            };
            int u = dfs(0).first;
            int diameter = dfs(u).second;
            return diameter;
        };
        int d1 = dia(edges1);
        int d2 = dia(edges2);
        return max({max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};