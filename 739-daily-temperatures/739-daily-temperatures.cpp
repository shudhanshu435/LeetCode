class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        int hot=0;
        vector<int>vec(n,0);
        for(int curr=n-1;curr>=0;curr--){
            int temp=temperatures[curr];
            if(temp>=hot){
                hot=temp;
                continue;
            }
            int days=1;
            while(temperatures[curr+days]<=temp)days+=vec[curr+days];
            vec[curr]=days;
        }
        return vec;
    }
};