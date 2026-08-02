class Solution {
public:
    int memo[501][501];
    int rec(vector<int>& piles, int i, int j){
        if(i>j)return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        int lt=piles[i]+min(rec(piles,i+2,j),rec(piles,i+1,j-1));
        int rt=piles[j]+min(rec(piles,i+1,j-1),rec(piles,i,j-2));

        return memo[i][j]=max(lt,rt);
    }
    bool stoneGame(vector<int>& piles) {
        memset(memo,-1,sizeof(memo));
        int alice=rec(piles,0,piles.size()-1);
        int sum=accumulate(piles.begin(),piles.end(),0);
        return alice>=sum-alice;
    }
};