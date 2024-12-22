class Solution {
public:
    int nextGreat(int fir, int sec, vector<int>& heights){
        if(fir == sec) return fir;
        if(heights[sec] > heights[fir]) return sec;
        int big = heights[fir];
        int n = heights.size();
        for(int i = sec ; i < n ; i++){
            if(big < heights[i]) return i;
        }
        return -1;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>ans;
        map<pair<int,int>,int>mp;
        for(int i = 0 ; i < n ; i++){
            int a = queries[i][0];
            queries[i][0] = min(queries[i][0], queries[i][1]);
            queries[i][1] = max(a, queries[i][1]);
            if(mp.find({queries[i][0], queries[i][1]}) != mp.end()) ans.push_back(mp[{queries[i][0], queries[i][1]}]);
            else{ 
                ans.push_back(nextGreat(queries[i][0], queries[i][1], heights));
                mp[{queries[i][0], queries[i][1]}] = ans[i];
            }
        }
        return ans;
    }
};