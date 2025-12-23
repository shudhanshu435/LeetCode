class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        // for(auto i:events)cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        int n=events.size();
        vector<long long>maxi(n,0);
        maxi[n-1]=events[n-1][2];
        vector<int>first(n);
        first[n-1]=events[n-1][0];
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(1ll*events[i][2],maxi[i+1]);
            first[i]=events[i][0];
        }
        // for(auto i:maxi)cout<<i<<" ";cout<<endl;
        long long ans=0;
        for(int i=0;i<n;i++){
            int num=events[i][1];
            auto up=upper_bound(first.begin(),first.end(),num);
            int ind=up-first.begin();
            if(ind==n)ans=max(ans,1ll*events[i][2]);
            else ans=max(ans,maxi[ind]+events[i][2]);
        }
        return ans;
    }
};