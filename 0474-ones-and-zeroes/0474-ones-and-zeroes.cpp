class Solution {
public:
    int dp[601][101][101];
    int cnt(string &s){
        return count(s.begin(),s.end(),'1');
    }
    int rec(vector<pair<int,int>>&vp, int one, int zero, int m, int n, int idx){
        if(vp.size()==idx)return 0;
        if(dp[idx][one][zero]!=-1)return dp[idx][one][zero];

        //skip
        int ans= rec(vp,one,zero,m,n,idx+1);

        //not skip if possible
        if(one+vp[idx].first<=n and zero+vp[idx].second<=m)
            dp[idx][one][zero]= max(ans,1+rec(vp,one+vp[idx].first,zero+vp[idx].second,m,n,idx+1));

        return dp[idx][one][zero]=max(ans,dp[idx][one][zero]);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vp;
        for(auto &i:strs){
            int nn=cnt(i);
            vp.push_back({nn,i.size()-nn});
        }
        memset(dp,-1,sizeof(dp));
        return rec(vp,0,0,m,n,0);
        return 0;
    }
};