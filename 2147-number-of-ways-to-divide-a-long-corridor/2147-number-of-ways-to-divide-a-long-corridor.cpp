class Solution {
public:
    const int MOD=1e9+7;
    int numberOfWays(string corridor) {

        int seats=0;
        for(char c:corridor)if(c=='S')seats++;
        if(seats==0 or seats%2!=0)return 0;

        long long ways=1;
        int seatCount=0;
        int plants=0;
        bool started=false;

        for(char c:corridor){
            if(c=='S'){
                seatCount++;
                if(seatCount==2){
                    if(started){
                        ways=(ways*1ll*(plants+1))%MOD;
                    }
                    started=true;
                    plants=0;
                    seatCount=0;
                }
            }
            else if(started and seatCount==0){
                plants++;
            }
        }

        return (int)ways;
    }
};