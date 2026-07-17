class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxValue + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        vector<long long> count(maxValue + 1, 0);

        for (int gcdValue = maxValue; gcdValue >= 1; gcdValue--) {
            long long total = 0;

            for (int multiple = gcdValue; multiple <= maxValue; multiple += gcdValue) {
                total += freq[multiple];
            }

            long long pairs = total * (total - 1) / 2;

            for (
                int multiple = 2 * gcdValue;
                multiple <= maxValue;
                multiple += gcdValue
            ) {
                pairs -= count[multiple];
            }

            count[gcdValue] = pairs;
        }

        vector<long long> prefix;
        vector<int> values;
        long long sum = 0;

        for (int gcdValue = 1; gcdValue <= maxValue; gcdValue++) {
            if (count[gcdValue] > 0) {
                sum += count[gcdValue];
                prefix.push_back(sum);
                values.push_back(gcdValue);
            }
        }

        vector<int> result;

        for (long long query : queries) {
            int index = lower_bound(
                prefix.begin(),
                prefix.end(),
                query + 1
            ) - prefix.begin();

            result.push_back(values[index]);
        }

        return result;
    }
};