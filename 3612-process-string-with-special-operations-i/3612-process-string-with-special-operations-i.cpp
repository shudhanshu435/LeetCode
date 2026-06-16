class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto &i:s){
            if(isalpha(i))ans+=i;
            else if(i=='*' and !ans.empty())ans.pop_back();
            else if(i=='#')ans+=ans;
            else reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};