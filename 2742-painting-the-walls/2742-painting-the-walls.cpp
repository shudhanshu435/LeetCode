class Solution {
public:
    int n;
    const int INF = 1e9;
    vector<vector<int>> dp;

    int solve(int i, int walls, vector<int>& cost, vector<int>& time) {

        if (walls >= n)
            return 0;

        if (i == n)
            return INF;

        if (dp[i][walls] != -1)
            return dp[i][walls];

        int notTake = solve(i + 1, walls, cost, time);

        int take =
            cost[i] + solve(i + 1, min(n, walls + 1 + time[i]), cost, time);

        return dp[i][walls] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, cost, time);
    }
};