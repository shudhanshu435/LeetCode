class Solution {
public:
    int countOdds(int low, int high) {
        return ((long long)high+1)/2-low/2;
    }
};