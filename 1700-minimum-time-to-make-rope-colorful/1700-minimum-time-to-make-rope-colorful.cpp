class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        colors+='{';
        int n=colors.size();
        int sum=0,maxi=0,ans=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,nt[i]);
            sum+=nt[i];
            if(colors[i]!=colors[i+1]){
                ans+=(sum-maxi);
                sum=0;
                maxi=0;
                // cout<<ans<<endl;
            }
        }
        return ans;
    }
};