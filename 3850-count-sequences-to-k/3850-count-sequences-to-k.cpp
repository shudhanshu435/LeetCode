class Solution {
public:
    using ll=long long;
    int n;
    vector<ll>vec;
    ll k;
    map<tuple<int,ll,ll>,ll>mp;
    string mulp(string a,string b){
        if(a=="0"||b=="0")return"0";
        int n=a.size();
        int m=b.size();
        vector<int>res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int d1=a[i]-'0';
                int d2=b[j]-'0';
                int p=d1*d2;
                int p1=i+j;
                int p2=i+j+1;
                int s=p+res[p2];
                res[p2]=s%10;
                res[p1]+=s/10;
            }
        }
        string ans="";
        for(int x:res){
            if(!(ans.empty()&&x==0))ans.push_back(x+'0');
        }
        return ans.empty()?"0":ans;
    }
    int solve(int ind, ll num, ll den){
        ll g=__gcd(num,den);
        num/=g;
        den/=g;

        if(ind==n)return (to_string(num)==mulp(to_string(k),to_string(den)))?1ll:0ll;

        auto state=make_tuple(ind,num,den);
        if(mp.count(state))return mp[state];

        ll ans=0;
        ans+=solve(ind+1,num*vec[ind],den);
        ans+=solve(ind+1,num,den*vec[ind]);
        ans+=solve(ind+1,num,den);

        return mp[state]=ans;
    }
    int countSequences(vector<int>& nums, long long target) {
        vec.assign(nums.begin(),nums.end());
        n=nums.size();
        k=target;
        mp.clear();
        return solve(0,1,1);
    }
};