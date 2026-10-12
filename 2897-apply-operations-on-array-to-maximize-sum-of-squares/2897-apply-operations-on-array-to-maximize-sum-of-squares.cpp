class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(33, 0);

        for (int &i : nums) {
            int j = 0;

            while (i) {
                freq[j] += (i & 1);
                i /= 2;
                j++;
            }
        }

        long long ans = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < k; i++) {
            long long add = 0, fac = 1;

            for (int j = 0; j < 33; j++) {
                if (freq[j]) {
                    add += fac;
                    freq[j]--;
                }

                fac *= 2;
            }

            add %= mod;
            ans = (ans + add * add % mod) % mod;
        }

        return ans;
    }
};