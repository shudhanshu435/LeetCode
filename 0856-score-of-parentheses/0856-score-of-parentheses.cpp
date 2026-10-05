class Solution {
public:
    int scoreOfParentheses(string s) {
        int sc=0,d=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')d++;
            else{
                d--;
                if(s[i-1]=='(')sc+=(1<<d);
            }
        }
        return sc;
    }
};