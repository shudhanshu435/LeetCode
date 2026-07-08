class Solution {
public:
    static const long long MOD=1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
    
        vector<long long>pref(n),pow10(n+1);
        vector<int>cnt(n);
    
        pow10[0]=1;
        for(int i=1;i<=n;i++)pow10[i]=(pow10[i-1]*10)%MOD;
    
        if(s[0]!='0'){
            pref[0]=s[0]-'0';
            cnt[0]=1;
        }
    
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1];
            cnt[i]=cnt[i-1];
            if(s[i]!='0'){
                pref[i]=(pref[i]*10+(s[i]-'0'))%MOD;
                cnt[i]++;
            }
        }

        vector<long long>psum(n,0);
        psum[0]=(s[0]-'0');
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+(s[i]-'0');
        }
        vector<int>vv;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int tot=cnt[r]-(l>0?cnt[l-1]:0);
            long long res=pref[r];
            if(l>0){
                long long sub=(pref[l-1]*pow10[tot])%MOD;
                res=(res-sub+MOD)%MOD;
            }
            long long ans;
            if(l!=0)ans=(res*(psum[r]-psum[l-1]))%MOD;
            else ans=(res*psum[r])%MOD;
            vv.push_back((int)ans);
            // cout<<res<<endl;
        }
        return vv;
    }
};