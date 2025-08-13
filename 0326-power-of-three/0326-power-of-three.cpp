class Solution {
public: 
    bool recur(int n){
        if(n==1)return 1;
        if(n%3!=0 or n==0)return 0;
        return recur(n/3);
    }
    bool isPowerOfThree(int n) {
        return recur(n);
    }
};