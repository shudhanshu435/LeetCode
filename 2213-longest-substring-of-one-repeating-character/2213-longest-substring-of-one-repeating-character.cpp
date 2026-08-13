class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> seg;

    Node merge(Node& a, Node& b) {
        if (a.len == 0)
            return b;
        if (b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.prefix = a.prefix;

        if (a.prefix == a.len && a.rightChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }

        // Suffix
        res.suffix = b.suffix;

        if (b.suffix == b.len && a.rightChar == b.leftChar) {
            res.suffix = b.len + a.suffix;
        }

        // Best answer inside either half
        res.best = max(a.best, b.best);

        // A repeating substring can cross the middle
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        int k = queryIndices.size();

        seg.resize(4 * n + 5);

        // Build segment tree
        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            // Update the character
            update(1, 0, n - 1, idx, c);

            // Root contains the answer for the whole string
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};