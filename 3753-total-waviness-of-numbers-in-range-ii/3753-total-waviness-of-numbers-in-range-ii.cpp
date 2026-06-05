class Solution {
    static inline int waves[570];
    static inline bool init = []() {
        int j = 0;
        for (int i = 0; i < 1000; i++) {
            int r = i % 10;
            int m = (i / 10) % 10;
            int l = (i / 100) % 10;
            if ((m > max(l, r)) | (m < min(l, r)))
                waves[j++] = i;
        }
        return 0;
    }();

public:
    long long totalWaviness(long long num1, long long num2) {
        return waveCount(num2) - waveCount(num1 - 1);
    }

    long long waveCount(long long num) {
        if (num < 100)
            return 0;
        long long res = 0;
        for (const auto& i : waves)
            res += countWays(num, i);
        return res;
    }

    long long countWays(long long num, int pattern) {
        long long type = pattern < 100;
        long long ways = 0, mult = 1;
        for (int i = 0; i < 16; i++) {
            if (mult * 100 > num)
                break;
            long long pre = num / (mult * 1000);
            long long cur = (num / mult) % 1000;
            long long suff = num % mult;
            long long cnt = 0, edge = 0;
            if (cur > pattern)
                cnt = pre - type + 1;
            else if (cur == pattern) {
                cnt = max(0LL, pre - type);
                edge = (pre >= type) * (suff + 1);
            } else if (cur < pattern)
                cnt = max(0LL, pre - type);
            ways += cnt * mult + edge;
            mult *= 10;
        }
        return ways;
    }
};