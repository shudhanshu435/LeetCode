class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int op=0;
        bool b=0;
        queue<char>q;
        for(auto i:s){
            q.push(i);
            if(i=='(')op++;
            else op--;
            if(op==0){
                q.pop();
                while(!q.empty()){
                    char ch=q.front();
                    q.pop();
                    ans+=ch;
                }
                ans.pop_back();
            }
        }
        return ans;
    }
};