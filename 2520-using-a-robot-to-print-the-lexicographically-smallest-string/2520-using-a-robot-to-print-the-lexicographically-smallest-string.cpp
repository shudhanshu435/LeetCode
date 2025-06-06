class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<int> a(n);
        for(int i = n-1;i>=0;i--){
            a[i] = s[i]-'a';
            if(i+1<n) a[i] = min(a[i], a[i+1]);
        }
        stack<int> st;

        string ans = "";
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top() <= a[i]){
                ans += (st.top() + 'a');
                st.pop();
            }
            st.push(s[i]-'a');
        }
        while(!st.empty()){
            ans += (st.top() + 'a');
            st.pop();
        }
        return ans;
    }
};