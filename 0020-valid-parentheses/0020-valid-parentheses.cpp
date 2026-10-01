class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
             char ch=s[i];
             if(ch=='('||ch=='{'||ch=='[')st.push(ch);
             else {
                 if(st.empty())return 0;
                 if(!st.empty()&&ch==')'&&st.top()!='(')return 0;
                 else if(!st.empty()&&ch==']'&&st.top()!='[')return 0;
                 else if(!st.empty()&&ch=='}'&&st.top()!='{')return 0;
                 else st.pop();
             }
        }
        if(st.empty())return 1;
        return 0;
    }
};