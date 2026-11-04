class Solution {
public:
    long long dp[100000][16];
    vector<long long> getMove(vector<int>& nums, int x) {

        int n = nums.size();
        vector<long long> res(n - x + 1, 0);

        multiset<int> mx; // left
        multiset<int> mn; // right

        long long mx_sum = 0;
        long long mn_sum = 0;

        // first window
        for (int i = 0; i < x; i++) {
            int num = nums[i];

            if (mx.empty() || num <= *mx.rbegin()) {
                mx.insert(num);
                mx_sum += num;
            } else {
                mn.insert(num);
                mn_sum += num;
            }

    // allowing mx can be equal or one more than mn but mn can be atmost equal to mx.
            while (mx.size() > mn.size() + 1) {
                int val = *mx.rbegin();
                mx.erase(prev(mx.end()));
                mx_sum -= val;

                mn.insert(val);
                mn_sum += val;
            }

            while (mn.size() > mx.size()) {
                int val = *mn.begin();
                mn.erase(mn.begin());
                mn_sum -= val;

                mx.insert(val);
                mx_sum += val;
            }
        }

        // cost for first window
        long long med = *mx.rbegin();
        res[0] = med * mx.size() - mx_sum + mn_sum - med * mn.size();

        //sliding
        for (int i = x; i < n; i++) {

            int add = nums[i];
            int rem = nums[i - x];

            // add new
            if (add <= *mx.rbegin()) {
                mx.insert(add);
                mx_sum += add;
            } else {
                mn.insert(add);
                mn_sum += add;
            }

            // remove old
            if (mx.find(rem) != mx.end()) {
                mx.erase(mx.find(rem));
                mx_sum -= rem;
            } else {
                mn.erase(mn.find(rem));
                mn_sum -= rem;
            }

            // balance
            while (mx.size() > mn.size() + 1) {
                int val = *mx.rbegin();
                mx.erase(prev(mx.end()));
                mx_sum -= val;

                mn.insert(val);
                mn_sum += val;
            }

            while (mn.size() > mx.size()) {
                int val = *mn.begin();
                mn.erase(mn.begin());
                mn_sum -= val;

                mx.insert(val);
                mx_sum += val;
            }

            long long med = *mx.rbegin();
            res[i - x + 1] =
                med * mx.size() - mx_sum + mn_sum - med * mn.size();
        }

        return res;
    }
    long long f(int i, int k, vector<int>& nums, int x,
                vector<long long>& move) {
        int n = nums.size();
        if (k == 0)
            return 0;
        if (i == n)
            return 1e15;
        if (dp[i][k] != -1)
            return dp[i][k];
        // take this size 'x' subarray starting from i
        long long take = 1e15;
        if (i + x <= n) {
            take = move[i] + f(i + x, k - 1, nums, x, move);
        }
        // not taking
        long long not_take = f(i + 1, k, nums, x, move);
        return dp[i][k] = min(take, not_take);
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        vector<long long> move = getMove(nums, x);
        return f(0, k, nums, x, move);
    }
};