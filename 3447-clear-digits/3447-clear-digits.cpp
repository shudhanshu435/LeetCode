class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]))st.push(s[i]);
            else if(!st.empty())st.pop();
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};