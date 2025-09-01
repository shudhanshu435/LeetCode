using p = pair<double, pair<int, int>>;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        priority_queue<p>pq;
        int n=classes.size();
        for(auto i:classes){
            int a=i[0],b=i[1];
            double curr=(double)a/b;
            double inc=((double)(a+1)/(b+1))-curr;
            pq.push(make_pair(inc,make_pair(a,b)));
        }
        while(ex--){
            double t=pq.top().first;
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            pq.pop();
            a++;b++;
            double inc=((double)(a+1)/(b+1))-(double)a/b;
            pq.push(make_pair(inc,make_pair(a,b)));
        }
        double ans=0.00000;
        while(!pq.empty()){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            ans+=(double)a/b;
            pq.pop();
        }
        return ans/n;
    }
};