class Solution {
public:
    unsigned long long near2(unsigned long long n) {
        if(n==0)return 0;

        unsigned long long power=1;
        while(power<n) {
            power<<=1;
        }
        return power>>1;
    }

    int cmpexpo(unsigned long long power) {
        int exponent = 0;
        while (power >>= 1) {
            exponent++;
        }
        return exponent;
    }

    char kthCharacter(long long k, vector<int>& op) {
        int cur=0;
        while(k>1){
            unsigned long long p = near2(k);
            int exp=cmpexpo(p)+1;
            k=k-p;

            if(op[exp-1]==1)cur--;
        }

        cur%=26;
        return 'a'-cur;
    }
};