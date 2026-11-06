class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> vec;
        for (auto &i : logs) vec.push_back({i[1], i[0]});  
        sort(vec.begin(), vec.end());

        int m = queries.size();
        vector<pair<int,int>> q;                        
        for (int i = 0; i < m; i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        vector<int> cnt(n + 1, 0), ans(m);           
        int active = 0;                                 
        int l = 0, r = 0;

        for (int k = 0; k < m; k++) {
            int qt = q[k].first;

            while (r < vec.size() && vec[r][0] <= qt) {
                if (cnt[vec[r][1]]++ == 0) active++;
                r++;
            }
            while (l < r && vec[l][0] < qt - x) {
                if (--cnt[vec[l][1]] == 0) active--;
                l++;
            }
            ans[q[k].second] = n - active;
        }
        return ans;
    }
};