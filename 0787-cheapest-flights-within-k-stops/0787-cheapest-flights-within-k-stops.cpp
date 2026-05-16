class Solution {
public:
    using p =pair<int,pair<int,int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,vector<pair<int,int>>>mp;
        priority_queue<p,vector<p>,greater<p>>pq;

        for(auto &f:flights){
            int x=f[0];
            int y=f[1];
            int z=f[2];
            mp[x].push_back({y,z});
        }

        pq.push({0,{src,0}});
        vector<int>vis(n,INT_MAX);
        int ans=INT_MAX;

        while(!pq.empty()){
            int c=pq.top().first;
            int t=pq.top().second.first;
            int s=pq.top().second.second;
            pq.pop();

            if(t==dst)return c;
            if(s>k)continue;

            if(vis[t]<=s)continue;
            vis[t]=s;

            for(auto &i:mp[t]){
                int next=i.first;
                int price=i.second;

                pq.push({c+price,{next,s+1}});
            }
        }

        return -1;

    }
};