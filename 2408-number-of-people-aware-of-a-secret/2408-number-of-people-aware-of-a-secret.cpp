class Solution {
public:
    const int mod=1e9+7;
    int delay, forget;
    vector<int> dp;

    int f(int i) {
        if (i<0) return 0; 
        if (dp[i]!=-1) return dp[i];
        if (i==0) return dp[i]=1;   // day 0: 1 person 
        if (i<delay) return dp[i]=0; // no new sharers yet

        long long ans=0;
        for (int j = max(0, i-forget+1); j<=i-delay; j++) 
            ans+=f(j);

        return dp[i]=ans%mod;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->delay = delay;
        this->forget = forget;
        dp.assign(n, -1);

        long long ans=0;
        for (int i=n-forget; i<n; i++) {
            ans+=f(i);
        }
        return ans%mod;
    }
};