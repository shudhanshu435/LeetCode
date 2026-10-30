class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            mp[u].push_back({v,w});
        }

        unordered_map<int, unordered_map<int,long long>>dist;
        using p=pair<long long,pair<int,int>>;
        priority_queue<p,vector<p>,greater<p>>pq;

        dist[0][1]=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            long long c=pq.top().first;
            int node=pq.top().second.first;
            int con=pq.top().second.second;
            pq.pop();

            if(dist[node][con]!=c)continue;
            for(auto &[next,w]:mp[node]){
                int nw;
                if(labels[next]==labels[node])nw=con+1;
                else nw=1;
                if(nw>k)continue;

                long long mini=c+w;
                if(!dist[next].count(nw) or mini<dist[next][nw]){
                    dist[next][nw]=mini;
                    pq.push({mini,{next,nw}});
                }
            }
        }

        long long ans=LLONG_MAX;
        for(int i=1;i<=k;i++){
            if(dist[n-1].count(i))ans=min(ans,dist[n-1][i]);
        }

        return (ans==LLONG_MAX)?-1:ans;
    }
};