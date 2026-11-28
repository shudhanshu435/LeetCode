class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxF = 0;
        int m = items[0][1];
        for (auto& it : items) {
            maxF = max(maxF, it[0]);
            m = min(m, it[1]);
        }

        vector<int> freq(maxF + 1, 0);
        for (auto& it : items) freq[it[0]]++;

        vector<int> multiples(maxF + 1, 0);
        for (int f = 1; f <= maxF; f++) {
            if (freq[f] == 0) continue;
            for (int x = f; x <= maxF; x += f) {
                multiples[f] += freq[x];
            }
        }

        vector<pair<int, int>> bonuses;
        for (auto& it : items) {
            if (it[1] < 2LL * m) {
                bonuses.push_back({it[1], multiples[it[0]] - 1});
            }
        }
        sort(bonuses.begin(), bonuses.end());

        long long rem = budget, k = 0;
        for (auto& [price, count] : bonuses) {
            long long take = min<long long>(count, rem / price);
            k += take;
            rem -= take * price;
        }

        return 2 * k + rem / m;
    }
};