class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        string ans="";
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else {
                string curr="";
                while(st.top()!='['){
                    curr=st.top()+curr;
                    st.pop();
                }
                st.pop();
                // long long num=0;
                string cc="";
                while(!st.empty() and st.top()>='0' and st.top()<='9'){
                    cc=st.top()+cc;
                    // cout<<cc<<endl;
                    // int ch = (st.top()-48);
                    st.pop();
                    // num=num*10 + ch;
                }
                int num=stoi(cc);
                for(int i=0;i<num;i++){
                    for(int j=0;j<curr.length();j++){
                        st.push(curr[j]);
                    }
                }
                // cout<<num<<endl;
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};