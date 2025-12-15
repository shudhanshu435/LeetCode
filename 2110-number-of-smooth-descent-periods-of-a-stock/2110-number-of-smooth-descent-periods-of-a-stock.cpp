class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        int cnt=1;
        long long ans=n;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1)cnt++;
            else{
                ans+=cnt*1ll*(cnt-1)/2;
                cnt=1;
            }
        }
        ans+=cnt*1ll*(cnt-1)/2;
        return ans;
    }
};