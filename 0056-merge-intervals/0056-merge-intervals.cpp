class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0,j=1;
        vector<vector<int>>v;
        int n=intervals.size();
        while(j<n){
            if(intervals[j][0]<=intervals[i][1]){
                intervals[i][1]=max(intervals[i][1],intervals[j][1]);
            }
            else{
                v.push_back({intervals[i][0],intervals[i][1]});
                i=j;
            }
            j++;
        }
        v.push_back({intervals[i][0],intervals[i][1]});
        return v;
    }
};