
class Solution {
    vector<vector<int>> adj;
    vector<int> tin, tout, depth, parent;
    vector<vector<int>> up;
    vector<int> bit;
    int timer = 0;

    void dfs(int u, int p, int d, string& s) {
        parent[u] = p;
        depth[u] = d;
        tin[u] = ++timer;

        for (int v : adj[u]) {
            if (v == p)
                continue;
            dfs(v, u, d + 1, s);
        }

        tout[u] = timer;
    }

    void updateBIT(int i, int val) {
        for (; i < (int)bit.size(); i += i & -i) {
            bit[i] ^= val;
        }
    }

    int queryBIT(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res ^= bit[i];
        }
        return res;
    }

    void buildLCA(int n) {
        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n));
        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; diff; j++, diff >>= 1) {
            if (diff & 1)
                u = up[j][u];
        }

        if (u == v)
            return u;

        for (int j = (int)up.size() - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        parent.resize(n);
        timer = 0;

        dfs(0, 0, 0, s);
        buildLCA(n);

        bit.assign(n + 2, 0);

        vector<int> mask(n);
        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
            updateBIT(tin[u], mask[u]);
            updateBIT(tout[u] + 1, mask[u]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                updateBIT(tin[u], delta);
                updateBIT(tout[u] + 1, delta);
                mask[u] = newMask;
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int pathMask = queryBIT(tin[u]) ^ queryBIT(tin[v]) ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};