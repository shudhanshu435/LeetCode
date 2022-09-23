class Solution {
public:
    
    int nBits(int n) {
		  return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long result = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = nBits(i);
            result = ((result << len) % MOD + i) % MOD;
        }
        return result;
    }
};