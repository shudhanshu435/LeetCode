class Solution {
public:
    set<string> parse(const string& s, int& idx) {
        vector<vector<set<string>>> groups;
        groups.push_back({});

        while (idx < s.length()) {
            char ch = s[idx];

            if (isalpha(ch)) {
                groups.back().push_back({string(1, ch)});
                idx++;
            } else if (ch == '{') {
                idx++;
                set<string> subResult = parse(s, idx);
                groups.back().push_back(subResult);
            } else if (ch == ',') {
                groups.push_back({});
                idx++;
            } else if (ch == '}') {
                idx++;
                break;
            }
        }

        set<string> result;

        for (const auto& group : groups) {
            if (group.empty()) continue;

            set<string> combined = {""};
            for (const auto& termSet : group) {
                set<string> nextCombined;
                for (const string& a : combined) {
                    for (const string& b : termSet) {
                        nextCombined.insert(a + b);
                    }
                }
                combined = move(nextCombined);
            }
            result.insert(combined.begin(), combined.end());
        }

        return result;
    }
    vector<string> braceExpansionII(string expression) {
        int index = 0;
        set<string> resultSet = parse(expression, index);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};