class Solution {
public:
    int MOD=1000000007;
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int i=0;
        vector<int>vec;
        for(int i=0;i<32;i++){
            if(n&(1<<i))vec.push_back(1<<i);
        }

        vector<long long>v;
        v.push_back(vec[0]%MOD);
        for(int i=1;i<vec.size();i++){
            v.push_back((v.back()*1ll*vec[i])%MOD);
        }

        vector<int>ans;
        for(vector<int>vv:queries){
            if(vv[0]==0){
                ans.push_back(v[vv[1]]);
            }
            else{
                long long numerator = v[vv[1]];
                long long denominator = v[vv[0] - 1];
                long long inv = modPow(denominator, MOD - 2); // modular inverse
                ans.push_back((int)((numerator * inv) % MOD));
            }
        }

        return ans;
    }
};