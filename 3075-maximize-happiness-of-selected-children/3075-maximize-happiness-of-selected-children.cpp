class Solution {
public:
    long long maximumHappinessSum(vector<int>& hpp, int k) {
        vector<long long>hp;
        for(auto &i:hpp)hp.push_back((long long)i);
        sort(hp.rbegin(),hp.rend());
        long long happy=0;
        long long cnt=1;
        for(int i=0;i<k;i++){
            happy+=hp[i];
            if(i+1<k)hp[i+1]=max(0ll,hp[i+1]-cnt);
            cnt++;
        }
        return happy;
    }
};