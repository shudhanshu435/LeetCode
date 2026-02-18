class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n){
            if(!((n%2)^((n/2)%2)))return 0;
            n/=2;
        }
        return 1;
    }
};