class Solution {
public:
    static vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n = nums.size();
        vector<unsigned long long> nIdx(n);
        for(int i=0; i<n; i++)
            nIdx[i]=((unsigned long long)nums[i]<<32)+i;
        
        // Sort nIdx
        sort(nIdx.begin(), nIdx.end());

        vector<vector<int>> group = {{(int)(nIdx[0]&UINT_MAX)}};
        int prev = nIdx[0]>>32;

        // Create groups based on the limit condition
        for (int i = 1; i < n; i++) {
            int I = nIdx[i]&UINT_MAX, x = nIdx[i]>>32;
            if (x - prev <= limit) 
                group.back().push_back(I);
             else 
                group.push_back({I});
            prev = x;
        }

        // Sort indices within each group and assign values to nums
        for (auto& seq : group) {
            vector<int> values;
            for (int index : seq) 
                values.push_back(nums[index]);

            sort(seq.begin(), seq.end());  
            for (int i = 0; i < seq.size(); i++) {
                nums[seq[i]] = values[i];
            }
        }

        return nums;
    }
};
