class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long,pair<long long,long long>>>p;
        int n=nums1.size();
        for(long long i=0;i<n;i++){
            p.push_back({(long long)nums1[i],{i,(long long)nums2[i]}});
        }
        sort(p.begin(),p.end());
        vector<long long>ans(n);
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        long long sum=0,psum=0;
        bool m=true;long long kk=0;
        for(int i=0;i<n;i++){
            if(m){
                sum=0;
                m=false;
            }
            if(p[i].first==kk){
                ans[p[i].second.first]=psum;
            }
            else {
                ans[p[i].second.first]=sum;
                psum=sum;
            }
            pq.push(p[i].second.second);
            sum+=p[i].second.second;
            // cout<<sum<<endl;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
                // cout<<sum<<endl;
            }
            kk=p[i].first;
        }
        return ans;
    }
};