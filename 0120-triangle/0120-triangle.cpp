class Solution {
public:
    int minimumTotal(vector<vector<int>>& tt) {
        int n=tt.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i-1>=j){
                    if(i-1>=0 and j-1>=0)tt[i][j]+=min(tt[i-1][j],tt[i-1][j-1]);
                    else tt[i][j]+=tt[i-1][j];
                }
                else tt[i][j]+=tt[i-1][j-1];
            }
        }
        int mini=INT_MAX;
        for(auto &i:tt[n-1])mini=min(mini,i);
        return mini;
    }
};