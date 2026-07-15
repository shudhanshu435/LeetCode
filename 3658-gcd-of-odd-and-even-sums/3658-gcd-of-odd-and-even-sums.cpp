class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return __gcd(n*n, n*(n+1));
    }
};