class Solution {
public:
    void rec(string cur, int o, int c, int n, vector<string>&ans){
        if(cur.length()==n*2){
            ans.push_back(cur);
            return;
        }
        if(o<n)rec(cur+"(",o+1,c,n,ans);
        if(c<o)rec(cur+")",o,c+1,n,ans);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        rec("",0,0,n,ans);
        return ans;
    }
};