class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& ww) {
        string ans="";
        for(auto i:words){
            int wt=0;
            for(auto v:i){
                wt+=ww[v-'a'];
            }
            wt%=26;
            ans+=('a'+(25-wt));
        }
        return ans;
    }
};