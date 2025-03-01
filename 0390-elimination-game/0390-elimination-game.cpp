class Solution {
public:
    int lastRemaining(int n) {
        int left=1,right=n;
        bool l=1;
        int k=1;
        int i=1;
        while(left<right){
            if(l){
                left+=k;
                if(n&1)right=right-k;
                n/=2;
                k=(1<<i++);
                l=0;
            }
            else{
                right-=k;
                if(n&1)left=left+k;
                n/=2;
                k=(1<<i++);
                l=1;
            }
        }
        return left;
    }
};