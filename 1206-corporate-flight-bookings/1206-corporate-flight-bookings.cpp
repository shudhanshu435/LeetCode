class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int>diff(n+1,0);
        for(auto v:b){
            diff[v[0]-1]+=v[2];
            diff[v[1]]-=v[2];
        }
        
        for(int i=1;i<n;i++)diff[i]=diff[i]+diff[i-1];
        diff.pop_back();

        return diff;
    }
};