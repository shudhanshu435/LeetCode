class Solution {
public:
const long long MOD = 1000000007;

    bool canFormSmallestUniqueSubarray (vector<int>& nums, int windowSize) {
        unordered_map<unsigned long long, int> uniqueString;
        unsigned long long hash;
        unsigned long long base;
        unsigned long long basePow;

        base = 911382323;
        basePow = 1;
        hash = 0;

        for ( int i = 0; i < windowSize - 1; i += 1 ) {
            basePow = (basePow * base) % MOD;
        }

        for ( int i = 0; i < windowSize; i += 1 ) {
            hash = (hash * base + nums[i]) % MOD;
        }

        uniqueString[hash] += 1;

        for ( int i = windowSize; i < nums.size(); i += 1 ) {
            hash = (hash - nums[i - windowSize] * basePow % MOD + MOD) % MOD;
            hash = (hash * base + nums[i]) % MOD;
            uniqueString[hash] += 1;
        }

        for ( auto& [key, value] : uniqueString ) {
            if ( value == 1 ) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int start; 
        int end;

        start = 1;
        end = nums.size();

        while ( start < end ) {
            int mid;

            mid = start + (end - start) / 2;

            if ( canFormSmallestUniqueSubarray(nums, mid) ) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};