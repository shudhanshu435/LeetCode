class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        int min_l = INT_MAX;
        for (int i = 0; i < n; i++) {
            min_l = min(min_l, landStartTime[i] + landDuration[i]);
        }

        int min_w = INT_MAX;
        for (int j = 0; j < m; j++) {
            min_w = min(min_w, waterStartTime[j] + waterDuration[j]);
        }

        for (int j = 0; j < m; j++) {
            ans = min(ans, max(waterStartTime[j], min_l) + waterDuration[j]);
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, max(landStartTime[i], min_w) + landDuration[i]);
        }

        return ans;
    }
};