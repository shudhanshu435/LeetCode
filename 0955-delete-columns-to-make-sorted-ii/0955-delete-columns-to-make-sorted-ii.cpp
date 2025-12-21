class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool needDelete = false;
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    needDelete = true;
                    break;
                }
            }
            if (needDelete) {
                ans++;
                continue;
            }
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] < strs[i + 1][j]) {
                    sorted[i] = true;
                }
            }
        }

        return ans;
    }
};
