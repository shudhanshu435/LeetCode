class Solution {
public:
    using p=tuple<int,int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i:flights){
            mp[i[0]].push_back({i[1],i[2]});
        }

        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;        
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,src,0});

        while(!pq.empty()){
            int node=get<1>(pq.top());
            int prc=get<0>(pq.top());
            int kk=get<2>(pq.top());
            pq.pop();
            if(prc>dist[node][kk])continue;
            if(kk==k+1)continue;
            for(auto &i:mp[node]){
                int x=i.first;
                int y=i.second;
                if(prc+y<dist[x][kk+1]){
                    dist[x][kk+1]=prc+y;
                    pq.push({prc+y,x,kk+1});
                }
            }

        }
        int ans=INT_MAX;
        for(int i=0;i<=k+1;i++)ans=min(ans,dist[dst][i]);
        return (ans==INT_MAX)?-1:ans;
    }
};