class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        auto mod = [](long long x, int k) { return (int)((x % k + k) % k); };

        vector<int> p(n + 1, 0);
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            p[i + 1] = mod(s, k);
        }

        int ans = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j <= n; ++j) {
            if (mp.count(p[j])) {
                ans = max(ans, j - mp[p[j]]);
            } else {
                mp[p[j]] = j;
            }
        }

        unordered_map<int, int> pos;
        for (int m = 0; m < n; ++m) {
            if (!pos.count(p[m])) {
                pos[p[m]] = m;
            }
            int x = mod(2LL * nums[m], k);
            for (int j = m + 1; j <= n; ++j) {
                int t = mod(p[j] - x, k);
                if (pos.count(t)) {
                    ans = max(ans, j - pos[t]);
                }
            }
        }

        return ans;
    }
};