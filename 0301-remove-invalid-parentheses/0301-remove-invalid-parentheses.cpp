class Solution {
    unordered_set<string> valid;
    string s, curr;

    void dfs(int i, int balance) {
        if (balance < 0) return;

        if (i == (int)s.size()) {
            if (balance == 0) valid.insert(curr);
            return;
        }

        char ch = s[i];

        if (ch != '(' && ch != ')') {
            curr.push_back(ch);
            dfs(i + 1, balance);
            curr.pop_back();
        } else {
            // keep
            curr.push_back(ch);
            dfs(i + 1, ch == '(' ? balance + 1 : balance - 1);
            curr.pop_back();

            // remove
            dfs(i + 1, balance);
        }
    }

public:
    vector<string> removeInvalidParentheses(string str) {
        s = str;
        dfs(0, 0);

        size_t maxLen = 0;
        for (const auto& x : valid) maxLen = max(maxLen, x.size());

        vector<string> ans;
        for (const auto& x : valid) {
            if (x.size() == maxLen) ans.push_back(x);
        }
        return ans;
    }
};