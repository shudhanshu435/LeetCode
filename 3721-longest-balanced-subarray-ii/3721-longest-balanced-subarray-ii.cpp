class SegmentTree {
public:
    int n;
    vector<int> min_tree, max_tree, lazy;

    SegmentTree(int size) {
        n = size;
        min_tree.assign(4 * n, 0);
        max_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            min_tree[node] += lazy[node];
            max_tree[node] += lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update_range(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > end || start > r || end < l)
            return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range(2*node, start, mid, l, r, val);
        update_range(2*node+1, mid+1, end, l, r, val);
        min_tree[node] = min(min_tree[2*node], min_tree[2*node+1]);
        max_tree[node] = max(max_tree[2*node], max_tree[2*node+1]);
    }

    int find_leftmost_zero(int node, int start, int end) {
        push(node, start, end);
        if (min_tree[node] > 0 || max_tree[node] < 0)
            return -1;
        if (start == end)
            return min_tree[node] == 0 ? start : -1;
        int mid = (start + end) / 2;
        int left = find_leftmost_zero(2*node, start, mid);
        if (left != -1)
            return left;
        return find_leftmost_zero(2*node+1, mid+1, end);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> prev;
        SegmentTree st(n);
        int res = 0;

        for (int r = 0; r < n; r++) {
            int v = nums[r];
            int val = (v % 2 == 0) ? 1 : -1;

            if (prev.count(v))
                st.update_range(1, 0, n-1, 0, prev[v], -val);

            st.update_range(1, 0, n-1, 0, r, val);
            prev[v] = r;

            int l = st.find_leftmost_zero(1, 0, n-1);
            if (l != -1 && l <= r)
                res = max(res, r - l + 1);
        }

        return res;
    }
};