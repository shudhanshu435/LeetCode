class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(max(0, n - k + 1));

        unordered_map<int,int> freq;

        for (int i = 0; i < k; ++i) freq[nums[i]]++;

        auto compute_x_sum = [&](unordered_map<int,int>& f)->int64_t {
            vector<pair<int,int>> items;
            items.reserve(f.size());
            for (auto &p : f) items.push_back({p.first, p.second});
            sort(items.begin(), items.end(), [](const auto& a, const auto& b){
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });
            long long sum = 0;
            int take = min<int>(x, (int)items.size());
            for (int i = 0; i < take; ++i) {
                sum += 1LL * items[i].first * items[i].second;
            }
            return sum;
        };

        ans.push_back((int)compute_x_sum(freq));

        for (int i = k; i < n; ++i) {
            int add = nums[i];
            int rem = nums[i - k];

            freq[add]++;
            if (--freq[rem] == 0) freq.erase(rem);

            ans.push_back((int)compute_x_sum(freq));
        }

        return ans;
    }
};