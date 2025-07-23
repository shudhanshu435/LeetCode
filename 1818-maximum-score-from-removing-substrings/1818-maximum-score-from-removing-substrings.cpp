class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a = 0;
        int b = 0;
        int l = min(x, y);
        int r = 0;

        for (char c : s) {
            if (c > 'b') {
                r += min(a, b) * l;
                a = 0;
                b = 0;
            } else if (c == 'a') {
                if (x < y && b > 0) {
                    b--;
                    r += y;
                } else {
                    a++;
                }
            } else {
                if (x > y && a > 0) {
                    a--;
                    r += x;
                } else {
                    b++;
                }
            }
        }

        r += min(a, b) * l;
        return r;
    }
};