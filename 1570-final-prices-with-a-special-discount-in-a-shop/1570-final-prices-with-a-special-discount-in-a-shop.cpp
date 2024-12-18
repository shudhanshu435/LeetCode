class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        ans[n-1]=prices[n-1];
        stack<int>s;
        s.push(prices[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() and s.top()>prices[i])s.pop();
            if(s.empty())ans[i]=prices[i];
            else {
                int cur=s.top();
                ans[i]=prices[i]-cur;
            }
            s.push(prices[i]);
        }
        return ans;
    }
};