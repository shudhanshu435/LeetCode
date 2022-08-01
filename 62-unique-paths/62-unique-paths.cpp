class Solution {
public:
    int uniquePaths(int m, int n) {
        int num=n+m-2;
        int t=m-1;
        double ans=1;
        for(int i=1;i<=t;i++){
            ans=ans*(num-t+i)/i;
        }

    return (int)ans;
    }
};

