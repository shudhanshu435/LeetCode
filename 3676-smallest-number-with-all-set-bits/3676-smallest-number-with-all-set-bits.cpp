class Solution {
public:
    int smallestNumber(int n) {
        int x=log2(n)+1;
        return (1<<x)-1;
    }
};