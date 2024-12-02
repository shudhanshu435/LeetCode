class Solution {
public:
    int solve(int n, int rem){
        if(rem==1)return n;
        if(n%rem==0)return n/rem + solve(rem, rem/2);
        else return solve(n,rem-1);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        return solve(n,n/2);
    }
};

// 24 12 6 3
// 30 15 