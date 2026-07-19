class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        vector<bool>vis(26,0);
        for(auto i:s){
            if(st.empty()){
                st.push(i);
                mp[i]--;
                vis[i-'a']=1;
            }
            else{
                mp[i]--;
                if(vis[i-'a'])continue;
                while(!st.empty() and st.top()>i and mp[st.top()]>0){
                    vis[st.top()-'a']=0;
                    st.pop();
                }
                st.push(i);
                vis[i-'a']=1;
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