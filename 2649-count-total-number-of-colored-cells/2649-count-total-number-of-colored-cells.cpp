class Solution {
public:
    long long coloredCells(int n) {
        long long ans = (2*n*1ll*n)-((n*2)-1);
        return ans;
    }
};