class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int,int>>p;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            p.push_back({startTime[i],endTime[i]});
        }
        // sort(p.rbegin(),p.rend());
        vector<int>v;
        v.push_back(p[0].first-0);
        for(int i=1;i<n;i++){
            v.push_back(p[i].first - p[i-1].second); //storing gaps
        }
        v.push_back(eventTime-p[n-1].second);
        // for(auto vv:v)cout<<vv<<" ";
        // cout<<endl;
        k=k+1;
        int kk=0;
        long long sum=0,ans=0;
        for(int i=0;i<n+1;i++){
            if(i<k)sum+=v[i];
            else{
                sum-=v[kk++]-v[i];
                ans=max(ans,sum);
            }
            ans=max(ans,sum);
            // cout<<sum<<" ";
        }

        return ans;
    }
};