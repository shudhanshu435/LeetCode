class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.length(),ones=0,zeroes;
        for(char ch:s){
            if(ch == '1')ones++;
        }
        zeroes = n - ones;
        if(zeroes == 0)return 0;
        for(int ops = 1;ops <= n;ops++){
            int tf = ops*k;
            if((tf - zeroes)%2 == 1)continue;
            if(ops&1){
                if(tf >= zeroes && tf <= zeroes*ops+ones*(ops-1))return ops;
            }else{
                if(tf >= zeroes && tf <= zeroes*(ops-1)+ones*(ops))return ops;
            }
        }
        return -1;
    }
};