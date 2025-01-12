class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();

        if(n&1)return 0;
        stack<int>op;
        stack<int>opcl;
        for(int i=0;i<n;i++){
            if(locked[i]=='0')opcl.push(i);
            else if(s[i]=='(')op.push(i);
            else if(s[i]==')'){
                if(!op.empty())op.pop();
                else if(!opcl.empty())opcl.pop();
                else return 0;
            }
        }

        while(!op.empty() and !opcl.empty() and op.top()<opcl.top()){
            op.pop();
            opcl.pop();
        }

        return op.empty();
    }
};


