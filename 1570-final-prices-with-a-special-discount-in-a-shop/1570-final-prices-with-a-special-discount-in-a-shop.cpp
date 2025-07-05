class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
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