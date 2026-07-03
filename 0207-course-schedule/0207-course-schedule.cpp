class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        unordered_map<int,int>mp;
        for(auto i:pre){
            mp[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(mp[i]==0)q.push(i);
        }
        int k=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            k++;
            for(auto i:adj[t]){
                mp[i]--;
                if(mp[i]==0){
                    q.push(i);
                    mp.erase(i);
                }
            }
        }
        if(q.empty() and k!=n)return 0;
        return 1;
    }
};