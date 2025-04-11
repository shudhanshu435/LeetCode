class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            int s=floor(log10(i))+1;
            if(s&1)continue;
            int s1=0;
            int hlf=s/2;
            int ii=i;
            while(ii){
                if(hlf){
                    hlf--;
                    s1+=ii%10;
                }
                else s1-=(ii%10);
                ii/=10;
            }
            if(s1==0)cnt++;
        }
        return cnt;
    }
};