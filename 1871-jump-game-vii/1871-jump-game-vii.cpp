class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        int n=s.size();
        queue<int>q;
        vector<bool>vis(n,0);
        q.push(0);
        vis[0]=1;       
        int f=1;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i==n-1)return 1;
            int ss=max(i+mn,f);
            int e=min(i+mx,n-1);
            for(int j=ss;j<=e;j++){
                if(s[j]=='0' and !vis[j]){
                    vis[j]=1;
                    q.push(j);
                }
            }
            f=max(f,e+1);
        }
        return 0;
    }
};