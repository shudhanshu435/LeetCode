class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& ii) {
        vector<vector<int>>vec(n);
        for(auto i:ii){
            vec[i[0]].push_back(i[1]);
        }
        vector<bool> suspicious(n, false);

        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();

            for (auto x : vec[t]) {
                if (!suspicious[x]) {
                    suspicious[x] = true;
                    q.push(x);
                }
            }
        }

        // Check if any outside method calls a suspicious method
        for (auto &e : ii) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return remaining methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};