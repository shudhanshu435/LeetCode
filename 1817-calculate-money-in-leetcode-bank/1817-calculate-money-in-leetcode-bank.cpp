class Solution {
public:
    int totalMoney(int n) {
        int m=n/7;
        int sum=0;
        while(m)sum+=7*((m--)+3);
        int g=0;
        g=n%7;
        int i=(n/7)+1;
        while(g--)sum+=i++;
        return sum;
    }
};