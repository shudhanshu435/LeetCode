class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/"){
                s.push(stoi(tokens[i]));
            }
            else{
                if(tokens[i]=="*"){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(a*b);
                }
                else if(tokens[i]=="-"){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(b-a);
                }
                else if(tokens[i]=="+"){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(a+b);
                }
                else {
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};