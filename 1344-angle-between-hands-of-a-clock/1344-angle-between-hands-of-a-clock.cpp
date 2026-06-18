class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12)hour=0;
        double h=minutes*6;
        double d=hour*30 + minutes*0.5;
        return min(abs(h-d),360-abs(h-d));
    }

};