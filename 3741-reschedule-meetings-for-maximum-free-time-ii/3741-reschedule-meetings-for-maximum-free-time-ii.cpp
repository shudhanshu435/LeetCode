class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int,int>>p;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            p.push_back({startTime[i],endTime[i]});
        }
        // sort(p.rbegin(),p.rend());
        vector<int>gap;
        for(int i=0;i<n;i++){
            gap.push_back(p[i].second - p[i].first);
        }

        vector<int>v;
        v.push_back(p[0].first-0);
        for(int i=1;i<n;i++){
            v.push_back(p[i].first-p[i-1].second);
        }
        v.push_back(eventTime-p[n-1].second);

        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:gap)cout<<i<<" ";
        // cout<<endl;

        int size=v.size();
        vector<int>suf(size,0),pre(size,0);
        pre[0]=v[0];
        for(int i=1;i<size;i++){
            pre[i]=max(pre[i-1],v[i]);
        }
        suf[size-1]=v[size-1];
        for(int i=size-2;i>=0;i--){
            suf[i]=max(suf[i+1],v[i]);
        }
        int ans=0;
        // for(auto i:pre)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:suf)cout<<i<<" ";
        // cout<<endl;
        int sum=0;
        for(int i=0;i<gap.size();i++){
            sum=v[i]+v[i+1];

            if(i-1>=0 and pre[i-1]>=gap[i]){
                sum+=gap[i];
            }
            else if(i+2<v.size() and suf[i+2]>=gap[i]){
                sum+=gap[i];
            }
            ans=max(ans,sum);
        }


        return ans;
        
    }
};