using P=pair<int,int>;

class Solution {
public:
    struct Cmp {
        bool operator()(const P& a, const P& b) const {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        priority_queue<P, vector<P>, Cmp>pq;
        for(int i=0;i<value.size();i++){
            pq.push({limit[i],value[i]});
        }
        long long ans=0;
        int curr=0;
        queue<int>q;
        while(!pq.empty()){
            ans+=pq.top().second;
            q.push(pq.top().first);
            pq.pop();
            int curr=q.size();
            // if(!pq.empty()){
            //     if(pq.top().first<=curr)curr--;
            //     pq.pop();
            // }
            // int tp=pq.top().first;
            while(!pq.empty() and pq.top().first<=curr)pq.pop();
            // if(!pq.empty() and tp<=curr){
            //     curr--;
            // }
            while(!q.empty()){
                if(q.front()<=curr)q.pop();
                else break;
            }
        }
        return ans;
    }
};