class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();

        if(n&1)return 0;
        // stack<int>op;
        // stack<int>opcl;
        // for(int i=0;i<n;i++){
        //     if(locked[i]=='0')opcl.push(i);
        //     else if(s[i]=='(')op.push(i);
        //     else if(s[i]==')'){
        //         if(!op.empty())op.pop();
        //         else if(!opcl.empty())opcl.pop();
        //         else return 0;
        //     }
        // }

        // while(!op.empty() and !opcl.empty() and op.top()<opcl.top()){
        //     op.pop();
        //     opcl.pop();
        // }


        //2nd approach
        int op=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' or locked[i]=='0'){
                op++;
            }
            else op--;

            if(op<0)return 0;
        }

        int cl=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' or locked[i]=='0'){
                cl++;
            }
            else cl--;

            if(cl<0)return 0;
        }

        return 1;
    }
};


