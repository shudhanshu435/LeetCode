class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        long long mini=INT_MAX;
        long long ans=0;
        unordered_map<int,int>mp,mp2,mp3;
        for(auto &i:b1){
            mp[i]++;
            mp3[i]++;
            mini=min(mini,(long long)i);
        }
        for(auto &i:b2){
            mp2[i]++;
            mp3[i]++;
            mini=min(mini,(long long)i);
        }
        vector<int> A, B;
        for(auto &[a,b]:mp3)if(b&1)return -1;
        for (auto &[k, _] : mp3) {
            int d1 = mp[k];
            int d2 = mp2[k];
            int diff = abs(d1 - d2) / 2;

            if (d1 > d2) A.insert(A.end(), diff, k);
            else if (d2 > d1) B.insert(B.end(), diff, k);
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());

        long long cost = 0;
        for (size_t i = 0; i < A.size(); ++i) {
            cost += min(2 * mini, (long long)min(A[i], B[i]));
        }

        return cost;
    }
};