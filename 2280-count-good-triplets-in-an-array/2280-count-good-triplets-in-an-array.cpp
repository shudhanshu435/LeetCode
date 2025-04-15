#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less<>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i)
            pos2[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = pos2[nums1[i]];

        vector<int> leftLess(n), rightGreater(n);
        ordered_set os_left;
        for (int i = 0; i < n; ++i) {
            leftLess[i] = os_left.order_of_key(mapped[i]);
            os_left.insert(mapped[i]);
        }

        ordered_set os_right;
        for (int i = n - 1; i >= 0; --i) {
            rightGreater[i] = os_right.size() - os_right.order_of_key(mapped[i] + 1);
            os_right.insert(mapped[i]);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans += 1LL * leftLess[i] * rightGreater[i];

        return ans;
    }
};