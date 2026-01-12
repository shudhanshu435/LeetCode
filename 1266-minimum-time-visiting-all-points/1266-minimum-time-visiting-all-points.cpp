class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int n=p.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int x1=p[i][0];
            int y1=p[i][1];
            int x2=p[i+1][0];
            int y2=p[i+1][1];
            ans+=max(abs(x2-x1),abs(y2-y1));
        }
        return ans;
    }
};