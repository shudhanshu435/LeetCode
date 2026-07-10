class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& _nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> nums;
        for(int i = 0; i < n; i++) nums.emplace_back(_nums[i], i);
        
        sort(nums.begin(), nums.end());

        vector<int> changedIndex(n);
        vector<int> sortedNums;
        for(int i = 0; i < n; i++) {
            int val = nums[i].first, ind = nums[i].second;
            sortedNums.push_back(val);
            changedIndex[ind] = i;
        }

        int m = log2(n) + 1;
        vector<vector<int>> ancestors(n, vector<int>(m));
        for(int node = 0; node < n; node++) {
            int val = sortedNums[node] + maxDiff;
            ancestors[node][0] = upper_bound(sortedNums.begin(), sortedNums.end(), val) - sortedNums.begin() - 1;
        }

        for(int j = 1; j < m; j++) {
            for(int node = 0; node < n; node++) {
                ancestors[node][j] = ancestors[ancestors[node][j-1]][j-1];
            }
        }

        vector<int> res;
        for(auto &q: queries) {
            int u = q[0], v = q[1];
            if(u == v) {
                res.push_back(0);
                continue;
            }

            int a = changedIndex[u], b = changedIndex[v];
            if(a > b) swap(a, b);

            int curr = a;
            int jumps = 0;
            for(int j = m-1; j >= 0; j--) {
                if(ancestors[curr][j] < b) {
                    curr = ancestors[curr][j];
                    jumps += (1 << j);
                }
            }

            if(ancestors[curr][0] >= b) res.push_back(jumps + 1);
            else res.push_back(-1);
        }
        return res;
    }
};