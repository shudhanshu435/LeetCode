class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long num=0,sum=0;
        for(auto i:s){
            if(i>='1' and i<='9'){
                sum+=(i-'0');
                num=num*10+(i-'0');
            }
        }
        return num*sum;
    }
};