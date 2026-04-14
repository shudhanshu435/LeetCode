class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());   
        sort(factory.begin(),factory.end());
        long long INF = LLONG_MAX / 2;
        int n = robot.size(), m = factory.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][m] = INF;
        }

        for (int j = m - 1; j >= 0; j--) {
            long long prefix = 0;
            deque<pair<int, long long>> dq;
            dq.push_back({n, 0});

            for (int i = n - 1; i >= 0; i--) {
                prefix += abs(robot[i] - factory[j][0]);

                while (!dq.empty() && dq.front().first > i + factory[j][1]) {
                    dq.pop_front();
                }

                long long val = dp[i][j + 1] - prefix;
                while (!dq.empty() && dq.back().second >= val) {
                    dq.pop_back();
                }

                dq.push_back({i, val});
                dp[i][j] = dq.front().second + prefix;
            }
        }

        return dp[0][0];
    }
};