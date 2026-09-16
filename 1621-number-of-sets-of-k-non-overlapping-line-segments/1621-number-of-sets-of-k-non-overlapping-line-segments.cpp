class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD = 1e9 + 7;
        vector<int> prefix(n, 1);
        int totalPasses = 2 * k;
        for (int i = 0; i < totalPasses; i++) {
            for (int i = 1; i < n; i++) {
                prefix[i] = (prefix[i] + prefix[i - 1]) % MOD;
            }
        }
        return prefix[n - k - 1];
    }
};