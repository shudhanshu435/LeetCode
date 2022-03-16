class Solution {
public:
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; i--)
            nums1[i + n] = nums1[i];
        int i = 0, j = n, k = 0;
        while (i < m + n && k < n) {
            if (j < m + n && nums1[j] < nums2[k])
                nums1[i++] = nums1[j++];
            else
                nums1[i++] = nums2[k++];
        }
    }
};