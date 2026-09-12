class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        using State = pair<long long, vector<int>>;
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int i = 0; i < n; ++i) {
            int l = arr[i][0], r = arr[i][1], w = arr[i][2], id = arr[i][3];
            
            int prev = -1, low = 0, high = i - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid][1] < l) {
                    prev = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            for (int k = 1; k <= 4; ++k) {
                State best = dp[k][i]; 

                long long take_weight = w + dp[k - 1][prev + 1].first;
                vector<int> take_ids = dp[k - 1][prev + 1].second;
                take_ids.push_back(id);
                sort(take_ids.begin(), take_ids.end());

                State take = {take_weight, take_ids};

                if (take.first > best.first || (take.first == best.first && take.second < best.second)) {
                    best = take;
                }

                dp[k][i + 1] = best;
            }
        }

        return dp[4][n].second;
    }
};