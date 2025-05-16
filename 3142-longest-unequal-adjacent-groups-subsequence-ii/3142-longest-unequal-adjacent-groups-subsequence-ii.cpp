class Solution {
public:
    bool cHam(string& s1, string& s2){
        int diff=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])diff++;
        }
        if(diff>1)return 0;
        return diff==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& groups) {
        int n=w.size();
        vector<int>dp(n,1);
        vector<int>p(n,-1);
        int lon=1,lons=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(groups[j]!=groups[i] and w[i].length()==w[j].length() and cHam(w[i],w[j])){

                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        p[i]=j;

                        if(lon<dp[i]){
                            lon=dp[i];
                            lons=i;
                        }
                    }
                }

            }
        }
        vector<string>v;
        while(lons!=-1){
            v.push_back(w[lons]);
            lons=p[lons];
        }
        reverse(v.begin(),v.end());

        return v;
    }
};