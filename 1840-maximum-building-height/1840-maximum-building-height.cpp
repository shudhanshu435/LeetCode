class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        for (int i = 1; i < restrictions.size(); i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i - 1][1] + dist);
        }

        for (int i = restrictions.size() - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i + 1][1] + dist);
        }

        int ans = 0;

        for (int i = 1; i < restrictions.size(); i++) {

            long long id1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long dist = id2 - id1;

            long long peak = (h1 + h2 + dist) / 2;

            ans = max(ans, (int)peak);
        }

        return ans;
    }
};