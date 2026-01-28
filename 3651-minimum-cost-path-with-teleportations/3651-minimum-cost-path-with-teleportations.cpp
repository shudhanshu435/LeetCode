class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int INF = INT32_MAX / 2;
        vector<vector<int>> dp(n, vector<int>(m, INF));
        dp[n - 1][m - 1] = 0;
        vector<pair<int,int>> points;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) points.emplace_back(i, j);

        for (int t = 0; t <= k; ++t) {
            if (t > 0) {
                sort(points.begin(), points.end(), [&](auto& a, auto& b) {
                    if (grid[a.first][a.second] != grid[b.first][b.second])
                        return grid[a.first][a.second] < grid[b.first][b.second];
                    return dp[a.first][a.second] < dp[b.first][b.second];
                });

                int prev = INF;
                for (auto& p : points) {
                    prev = dp[p.first][p.second] = min(dp[p.first][p.second], prev);
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >= 0; --j) {
                    if (i + 1 < n) dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i + 1][j]);
                    if (j + 1 < m) dp[i][j] = min(dp[i][j], dp[i][j + 1] + grid[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};