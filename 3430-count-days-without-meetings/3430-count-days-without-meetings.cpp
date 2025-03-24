class Solution {
public: // [1,3],[5,7],[9,10]
    int countDays(int days, vector<vector<int>>& meet) {
        int n=meet.size();
        sort(meet.begin(),meet.end());
        int ans=0;
        for(int i=1;i<n;i++){
            if(meet[i][0]>meet[i-1][1]){
                ans+=meet[i][0]-meet[i-1][1]-1;
            }
            else meet[i][1]=max(meet[i][1],meet[i-1][1]);
        }
        ans+=meet[0][0]-1+days-meet[n-1][1];
        return ans;
    }
};