class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>vec;
        vec=heights;
        int ans=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<vec.size();i++)if(vec[i]!=heights[i])ans++;
        return ans;
    }
};