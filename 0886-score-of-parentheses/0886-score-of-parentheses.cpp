class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0,cnt=0;
        stack<char>st;
        for(auto i:s){
            if(i=='('){
                st.push(i);
                cnt++;
            }
            else{
                cnt--;
                if(st.top()=='(')ans+=(1<<cnt);
                st.push(i);
            }
        }
        return ans;
    }
};