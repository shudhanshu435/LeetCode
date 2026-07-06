class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in){
        int n=in.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(in[j][0]<=in[i][0] and in[j][1]>=in[i][1]){
                    cnt++;
                    break;
                }
            }
        }

        return n-cnt;
    }
};