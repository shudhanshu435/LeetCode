class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>p(n);
        p[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)p[i]=max(prices[i],p[i+1]);
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,p[i+1]-prices[i]);
        }
        return ans;
    }
};