class Solution {
public:
    //prim's algo
    using t=tuple<int,int,int>;
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                mp[i].push_back({j,dist});
                mp[j].push_back({i,dist});
            }
        }
        priority_queue<t,vector<t>,greater<t>>pq;
        vector<int>vis(n,0);
        int cost=0;
        pq.push({0,0,-1});
        while(!pq.empty()){
            auto [a,b,c]=pq.top();
            pq.pop();
            if(vis[b])continue;
            vis[b]=1;
            cost+=a;
            for(auto [x,y]:mp[b]){
                if(!vis[x]){
                    pq.push({y,x,b});
                }
            }
        }
        return cost;
    }
};