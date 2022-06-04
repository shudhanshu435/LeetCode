class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int m=timeSeries.size();
        int cnt=0;
        cnt+=duration;
        for(int i=0;i<m-1;i++){
            if(abs(timeSeries[i]-timeSeries[i+1])<duration)cnt+=abs(timeSeries[i]-timeSeries[i+1]);
            else cnt+=duration;
        }
        return cnt;
    }
};