typedef long long ll;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9 + 7;
        int m = words[0].size();
        int n = target.size();

        vector<vector<ll>> record(m, vector<ll>(26, 0));
        for (auto &word: words)
            for (int i = 0; i < m; i++)
                record[i][word[i] - 'a'] += 1;

        vector<vector<ll>> f(m, vector<ll>(n, 0));
        f[0][0] = record[0][target[0] - 'a'];
        for (int i = 1; i < m; i++) {
            f[i][0] = (f[i - 1][0] + record[i][target[0] - 'a']) % mod;
            for (int j = 1; j < n; j++) {
                f[i][j] = (f[i - 1][j] + ((f[i - 1][j - 1] * record[i][target[j] - 'a']) % mod)) % mod;
            }
        }

        return f[m - 1][n - 1];
    }
};