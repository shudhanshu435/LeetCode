class Solution {
public:
    vector<vector<int>>lcs(string &a, string &b){
        int m=a.length();
        int n=b.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp=lcs(str1,str2);
        int i=str1.size();
        int j=str2.size();
        string ans="";
        while(i>0 and j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    ans.push_back(str2[j-1]);
                    j--;
                }
                else{
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i>0){
            ans.push_back(str1[i-1]);i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};