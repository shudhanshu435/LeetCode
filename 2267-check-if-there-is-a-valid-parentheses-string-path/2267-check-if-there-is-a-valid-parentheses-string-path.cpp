class Solution {
public:
    int m, n;
    int memo[100][100][101];

    bool solve(int r, int c, int bal, vector<vector<char>>& grid) {
        if (grid[r][c] == '(')
            bal++;
        else
            bal--;

        if (bal < 0)
            return false;

        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (bal > remaining_steps)
            return false;

        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (memo[r][c][bal] != -1)
            return memo[r][c][bal];

        bool res = false;
        if (r + 1 < m) {
            res = res || solve(r + 1, c, bal, grid);
        }
        if (!res && c + 1 < n) {
            res = res || solve(r, c + 1, bal, grid);
        }

        return memo[r][c][bal] = res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n) % 2 == 0)
            return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= (m + n) / 2; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }

        return solve(0, 0, 0, grid);
    }
};