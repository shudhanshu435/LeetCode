class Solution {
public:
    using p=pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>vec(n,INT_MAX);
        vec[k-1]=0;
        unordered_map<int,vector<p>>mp;
        for(auto i:times){
            mp[i[0]-1].push_back({i[1]-1,i[2]});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto [time,node]=pq.top();
            pq.pop();
            // if(time>vec[node])continue;
            for(auto &[i,j]:mp[node]){
                if(j+time<vec[i]){
                    vec[i]=j+time;
                    pq.push({vec[i],i});
                }
            }
        }
        int ans=*max_element(vec.begin(),vec.end());
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};