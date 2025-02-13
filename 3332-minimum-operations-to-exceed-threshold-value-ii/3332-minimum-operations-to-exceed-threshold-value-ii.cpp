class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long>>pq;
        int cnt=0;
        for(auto i:nums)pq.push(i);
        if(pq.top()>=k)return 0;
        while(pq.size()>1){
            long long t=pq.top();
            pq.pop();
            long long st=pq.top();
            pq.pop();
            long long m= (min(t,st)*2 + max(t,st));
            pq.push(m);
            cnt++;
            if(pq.top()>=k)break;
        }
        return cnt;

    }
};