class Solution {
public:

    long long find_operation(vector<vector<long long>> &vt, long long left, long long right) {
        long long ops = 0;
        int level = vt.size();

        int i = left;
        while(i<=right) {
            for(int j = 0;j<level;j++) {
                if(vt[j][0] <= i && i < vt[j][1]) {
                    long long total_num = (min(right, vt[j][1]-1) - i + 1);
                    ops += (vt[j][2] * total_num);
                    i = vt[j][1];
                    break;
                }
            }
        }
        return (ops+1)/2;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        int n = queries.size();
        vector<vector<long long>> vt;
        for(long long i = 1,op = 1;i<1e16;i*=4,op++) {
            vt.push_back({i, i*4, op});
        }

        for(int i = 0;i<n;i++) {
            ans += find_operation(vt, queries[i][0], queries[i][1]);
        }
        return ans;
    }
};

