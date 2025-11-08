class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        int highest = 31 - __builtin_clz(n); 
        cout<<highest;
        int mask = 1 << highest;
        return (1 << (highest + 1)) - 1 - minimumOneBitOperations(n ^ mask);
    }
};