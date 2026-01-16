class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        sort(hf.begin(),hf.end());
        sort(vf.begin(),vf.end());
        int hs=hf.size();
        int vs=vf.size();
        unordered_map<int,bool>mp;

        int cur=m;
        for(int i=hs;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                mp[cur-hf[j]]=1;
            }
            mp[cur-1]=1;
            if(i!=0)cur=hf[i-1];
        }
        // for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;
        cur=n;
        int ans=-1;
        for(int i=vs;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(mp[cur-vf[j]]==1)ans=max(ans,cur-vf[j]);
            }
            if(mp[cur-1]==1)ans=max(ans,cur-1);
            if(i!=0)cur=vf[i-1];
        }
        if(ans==-1)return -1;
        return (ans*1ll*ans)%1000000007;
    }
};