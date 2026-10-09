class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    ans++;
                }
                else st.pop();
                if(i+1<n and s[i+1]!=')')
                    ans++;
                if(i+1>=n)ans++;
                if(i+1<n and s[i+1]==')')i++;
            }
        }
        return ans+st.size()*2;
        
    }
};