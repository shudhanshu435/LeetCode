class Solution {
public:
    int minimumChanges(string s, int k) {
        vector<vector<optional<int>>> memo(s.size(), vector<optional<int>>(k + 1, nullopt));
        vector<vector<optional<int>>> memo2(s.size(), vector<optional<int>>(s.size()+1, nullopt));

        auto get_cost_d = [&](int start, int len, int d, int limit = numeric_limits<int>::max()) {
            int cost = 0;
            for (int i = start, j = start + len - d; i < j; i += d, j -= d) {
                for (int part = 0; part < d; ++part) {
                    if (cost >= limit) return limit;
                    else cost += (s[part + i] != s[part + j]);
                }
            }
            return cost;
        };

        auto get_cost = [&](int start, int len) {
            auto& mem = memo2[start][len];
            if (mem.has_value()) return mem.value();
            int cost = get_cost_d(start, len, 1);
            int d = 2;
            for (; d * d < len && cost > 0; ++d) {
                if (len % d != 0) continue;
                cost = get_cost_d(start, len, d, cost);
                cost = get_cost_d(start, len, len / d, cost);
            }
            if (d * d == len)  {
                cost = get_cost_d(start, len, d, cost);
            }
            mem = cost;
            return cost;
        };

        auto dfs = [&](auto&& self, int start, int k) -> int {
            if (start == s.size()) return 0;
            auto& mem = memo[start][k];
            if (mem.has_value()) return mem.value();
            
            if (k == 1) {
                int cost = get_cost(start, s.size() - start);
                mem = cost;
                return cost;
            }

            int max_len = static_cast<int>(s.size()) - 2 * (k - 1) - start;
            int best = numeric_limits<int>::max();
            for (int len = 2; len <= max_len; ++len) {
                int first = get_cost(start, len);
                if (first >= best) continue;
                int rest = self(self, start + len, k - 1);
                best = min(best, first + rest);
            }
            mem = best;
            return best;
        };

        return dfs(dfs, 0, k);
    }
};