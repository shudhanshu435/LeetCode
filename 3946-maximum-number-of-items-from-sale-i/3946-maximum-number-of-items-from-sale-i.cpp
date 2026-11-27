class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        return a[1]<b[1];
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // sort(items.begin(),items.end(),cmp);
        // for(auto i:items)cout<<i[0]<<" "<<i[1]<<endl;

        vector<int>v;
        int n=items.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(j!=i and items[j][0]%items[i][0]==0)cnt++;
            }
            v.push_back(cnt);
        }
        vector<vector<int>>vv;
        int k=0;
        int mini=INT_MAX;
        for(auto i:items){
            vv.push_back({v[k++]+1,i[1]});
            mini=min(mini,i[1]);
        }

        vector<int>dp(budget+1,0);
        for(auto &x:vv){
            int val=x[0],w=x[1];
            for(int c=budget;c>=w;c--){
                dp[c]=max(dp[c],dp[c-w]+val);
            }
        }
        int ans=0;
        for(int c=0;c<=budget;c++){
            ans=max(ans,dp[c]+(budget-c)/mini);
        }
        return ans;
    }
};