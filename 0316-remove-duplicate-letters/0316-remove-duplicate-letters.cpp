class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>v(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            v[s[i]-'a']=i;
        }
        stack<char>st;
        vector<bool>vv(26,0);
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()>s[i]){
                if(vv[s[i]-'a']==1)break;
                if(i<v[st.top()-'a']){
                    vv[st.top()-'a']=0;
                    st.pop();
                }
                else break;
            }
            if(vv[s[i]-'a']==1)continue;
            st.push(s[i]);
            vv[s[i]-'a']=1;
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