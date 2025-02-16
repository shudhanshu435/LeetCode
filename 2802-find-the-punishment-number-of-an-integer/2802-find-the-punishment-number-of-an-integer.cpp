class Solution {
public:
    bool check(int sq, int currsum, int num){
        if(sq==0)return currsum==num;

        if(currsum>num)return false;

        return check(sq/10,currsum+sq%10,num) or check(sq/100,currsum+sq%100,num) or check(sq/1000,currsum+sq%1000,num) or check(sq/10000,currsum+sq%10000,num);

    }
    int punishmentNumber(int n) {
        int pun=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);

            if(check(sq,0,i))pun+=sq;
        }
        return pun;
    }
};