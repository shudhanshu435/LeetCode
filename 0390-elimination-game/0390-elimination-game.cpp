class Solution {
public:
    int solve(int n, bool isLeft){
        if(n==1)return 1;
        if (isLeft) {
            return 2 * solve(n / 2, false);
        } else {
            return 2 * solve(n / 2, true) - (n % 2 == 0 ? 1 : 0);
        }
    }
    int lastRemaining(int n) {
        return solve(n,1);
    }
};