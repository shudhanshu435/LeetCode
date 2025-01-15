class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int>vec(32,0);
        int cnt=__builtin_popcount(num2);
        int cn=__builtin_popcount(num1);
        if(cn==cnt)return num1;
        if(cnt<cn){
            cn=cn-cnt;
            int num=0;
            int k=0;
            while(num1){
                if(num1&1){
                    if(cn<=0)num+=(1<<k);
                    cn--;
                }
                num1/=2;
                k++;
            }
            return num;
        }
        else{
            cnt=cnt-cn;
            int num=num1;
            int k=0;
            while(cnt){
                if(!(num1&1)){
                    num+=(1<<k);
                    cnt--;
                }
                num1/=2;
                k++;
            }
            return num;
        }
        

        return 02;
    }
};