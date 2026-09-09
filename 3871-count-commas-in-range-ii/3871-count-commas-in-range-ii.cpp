class Solution {
public:
    long long countCommas(long long n) {

        if(n<1000)return  0;
        long long s=0;
        if(n>=1000){
            s+=min(n,999999ll)-999;
        }
        if(n>=1000000){
            s+=(min(n,999999999ll)-999999)*2;
        }
        if(n>=1000000000){
            s+=(min(n,999999999999ll)-999999999)*3;
        }
        if(n>=1000000000000ll){
            s+=(min(n,999999999999999ll)-999999999999ll)*4;
        }
        if(n>=1000000000000000ll){
            s+=(min(n,999999999999999999ll)-999999999999999ll)*5;
        }
        

        return s;
    }
};