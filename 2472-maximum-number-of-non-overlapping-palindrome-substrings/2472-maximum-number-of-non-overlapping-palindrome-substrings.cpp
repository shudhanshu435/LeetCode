class Solution {
public:
    bool expand(string& s, int left, int right, int k, int n, int& count, int& last_end) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            int length = right - left + 1;

            if (length >= k) {
                if (left > last_end) {
                    count++;
                    last_end = right;
                    return true;
                } else {
                    break;
                }
            }
            left--;
            right++;
        }
        return false;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1;

        for (int i = 0; i < n; ++i) {
            expand(s, i, i, k, n, count, last_end);
            
            expand(s, i, i + 1, k, n, count, last_end);
        }

        return count;
    }
};