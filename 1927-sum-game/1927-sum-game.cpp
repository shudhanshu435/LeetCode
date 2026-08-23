class Solution {
public:
    bool sumGame(string num) {
        int ls=0,rs=0,lq=0,rq=0;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]!='?')ls+=(num[i]-'0');
                else lq++;
            }
            else{
                if(num[i]!='?')rs+=(num[i]-'0');
                else rq++;
            }
        }
        if((lq+rq)&1)return 1;
        if(2*rs+9*rq==2*ls+9*lq)return 0;
        return 1;
    }
};