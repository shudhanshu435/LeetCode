class Solution {
public:
    long long distributeCandies(int n, int limit) {
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= 3; i++){
            vector<long long> pref = dp;
            for(int j = 1; j <= n; j++) pref[j] += pref[j - 1];
            for(int sum = 0; sum <= n; sum++){
                int r = sum, l = max(0, sum - limit);
                dp[sum] = pref[r] - (l > 0 ? pref[l - 1] : 0);
            }
        }
        return dp[n];
    }
};