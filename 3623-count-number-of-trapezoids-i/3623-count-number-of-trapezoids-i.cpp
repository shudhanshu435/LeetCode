class Solution {
public:
    int mod=1000000007;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto &i:points){
            mp[i[1]]++;
        }
        long long ans=0;
        vector<long long>v;
        for(auto &[a,b]:mp){
            if(b>1){
                v.push_back(b*1ll*(b-1)/2);
            }
        }
        if(v.size()<=1)return 0;
        int nn=v.size();
        vector<long long>suff(nn);
        suff[nn-1]=v[nn-1];
        for(int i=nn-2;i>=0;i--){
            suff[i]=v[i]+suff[i+1];
        }
        // for(int i=0;i<nn;i++){
        //     cout<<v[i]<<" "<<suff[i]<<endl;
        // }
        for(int i=0;i<nn-1;i++){
            ans=(ans+(v[i]*1ll*suff[i+1])%mod)%mod;
        }

        return ans;
    }
};