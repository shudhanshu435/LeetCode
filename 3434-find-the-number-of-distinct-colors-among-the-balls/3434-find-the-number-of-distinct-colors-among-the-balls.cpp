class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>balls,colors;
        int n=queries.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            int b=queries[i][0];
            int c=queries[i][1];

            if(balls.count(b)){
                int origColor=balls[b];
                colors[origColor]--;
                if(colors[origColor]==0)colors.erase(origColor);
            }
            balls[b]=c;
            colors[c]++;
            res.push_back(colors.size());
        }
        return res;

    }
};