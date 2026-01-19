class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> row(m, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n, 0));
        vector<vector<int>> diag(m+1, vector<int>(n+1, 0));
        vector<vector<int>> adiag(m+1, vector<int>(n+1, 0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                row[i][j+1] = row[i][j] + grid[i][j];
                col[i+1][j] = col[i][j] + grid[i][j];
                diag[i+1][j+1] = diag[i][j] + grid[i][j];
                adiag[i+1][j] = adiag[i][j+1] + grid[i][j];
            }
        }

        int maxSize = min(m, n);

        for (int k = maxSize; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int d1 = diag[i+k][j+k] - diag[i][j];
                    int d2 = adiag[i+k][j] - adiag[i][j+k];
                    if (d1 != d2) continue;

                    bool ok = true;

                    for (int x = 0; x < k; x++) {
                        int r = row[i+x][j+k] - row[i+x][j];
                        int c = col[i+k][j+x] - col[i][j+x];
                        if (r != d1 || c != d1) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) return k;
                }
            }
        }

        return 1;
    }
};
