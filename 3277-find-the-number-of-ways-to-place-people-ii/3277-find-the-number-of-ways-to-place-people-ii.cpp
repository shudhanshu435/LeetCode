class Solution {
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int y_mn=INT_MAX;
            for (int j = i - 1; j >= 0; j--) {

                if (points[j][1] >= points[i][1]) {
                  if(y_mn>points[j][1]){
                    y_mn=points[j][1];
                    ans++;
                  }
                }
            }
           
        }
        return ans;
    }
};