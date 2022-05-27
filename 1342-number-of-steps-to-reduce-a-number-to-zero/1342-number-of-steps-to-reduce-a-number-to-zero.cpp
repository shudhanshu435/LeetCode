class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        while(num){
            if(num&1)num-=1;
            else num/=2;
            cnt++;
        }
        return cnt;
    }
};