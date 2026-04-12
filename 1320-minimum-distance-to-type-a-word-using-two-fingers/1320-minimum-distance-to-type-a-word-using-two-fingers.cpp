class Solution {
public:
    int dp[301][27][27];

    pair<int,int>getCoord(int pos){
        return {pos/6, pos%6};
    }

    int Distance(int pos1, int pos2){
        auto[x1,y1]=getCoord(pos1);
        auto[x2,y2]=getCoord(pos2);
        return abs(x1-x2)+abs(y1-y2);
    }

    int solve(string &word, int i, int f1, int f2){
        if(i>=word.size())return 0;

        int curr=word[i]-'A';
        if(dp[i][f1][f2]!=-1)return dp[i][f1][f2];

        // used none
        if(f1==26 and f2==26)return dp[i][f1][f2]=solve(word,i+1,curr,f2);

        // f1 used
        if(f2==26){
            int movef2=solve(word,i+1,f1,curr);
            int movef1=Distance(f1,curr) + solve(word,i+1,curr,f2);

            return dp[i][f1][f2]=min(movef1,movef2);
        }

        // both used
        int movef1=Distance(f1,curr)+solve(word,i+1,curr,f2);
        int movef2=Distance(f2,curr)+solve(word,i+1,f1,curr);

        return dp[i][f1][f2]=min(movef1,movef2);

    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));

        return solve(word,0,26,26);
    }
};