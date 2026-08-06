class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(1){
            int m=i;
            int p=1;
            while(m){
                p=p*(m%10);
                m/=10;
            }
            if(p%t==0)return i;
            i++;
        }
    }
};