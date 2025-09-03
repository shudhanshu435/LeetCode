class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((n+1)/2 )*1ll* (m/2) + (n/2)*1ll*((m+1)/2);
    }
};