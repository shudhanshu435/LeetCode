class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string>q;
        int n=s.length();
        unordered_map<string,bool>mp;
        q.push(s);
        string ans=s;
        while(!q.empty()){
            string m=q.front();
            q.pop();
            ans=min(ans,m);
            for(int i=1;i<n;i+=2){
                m[i]=(((m[i]-'0')+a)%10)+'0';
            }
            if(mp[m]==false)q.push(m);
            mp[m]=1;
            string t=m;
            rotate(t.begin(), t.begin()+(n-b), t.end());
            if(mp[t]==false)q.push(t);
            mp[t]=1;
        }
        return ans;
    }
};