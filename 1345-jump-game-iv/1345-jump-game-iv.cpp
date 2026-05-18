class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<int>q;
        q.push(0);
        int n=arr.size();
        if(n==1)return 0;
        unordered_map<int,bool>vis;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        // vis[start]=1;
        int cnt=0;
        vis[0]=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int t=q.front();
                q.pop();
                // if(vis[t])continue;
                if(t==n-1)return cnt;
                if(t-1>=0 and !vis[t-1]){
                    vis[t-1]=1;
                    q.push(t-1);
                }
                if(t+1<n and !vis[t+1]){
                    vis[t+1]=1;
                    q.push(t+1);
                }
                for(auto &p:mp[arr[t]]){
                    if(!vis[p]){
                        vis[p]=1;
                        q.push(p);
                    }
                }
                mp[arr[t]].clear();
            }
            cnt++;
        }
        return -1;
    }
};