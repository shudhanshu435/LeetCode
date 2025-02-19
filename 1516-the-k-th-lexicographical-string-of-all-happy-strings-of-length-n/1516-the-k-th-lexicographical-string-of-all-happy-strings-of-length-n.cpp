class Solution {
public:
    void solve(int n, vector<string>& res, string& curr ){
        if(curr.length()==n){
            res.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!curr.empty() and curr.back()==ch)continue;
            //do
            curr.push_back(ch);
            solve(n,res,curr);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr="";
        vector<string>v;
        int cnt=0;
        solve(n,v,curr);
        if(k > v.size())return "";
        return v[k-1];
    }};