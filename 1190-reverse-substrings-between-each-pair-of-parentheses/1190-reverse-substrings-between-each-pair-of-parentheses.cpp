class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        queue<char>q;
        for(auto i:s){
            if(i!=')'){
                st.push(i);
            }
            else{
                while(st.top()!='('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};