class Solution {
public:
    vector<pair<int,int>>v{{100,0},{75,25},{50,50},{25,75}};
    double solve(double A, double B, vector<vector<double>>&memo){
        if(A<=0 and B<=0)return 0.5;
        if(A<=0)return 1;
        if(B<=0)return 0.0;
        if(memo[A][B]!=-1.0)return memo[A][B];
        double prob=0.0;
        for(auto &[a,b]:v){
            prob+=solve(A-a,B-b,memo);
        }
        return memo[A][B]=0.25*prob;
    }
    double soupServings(int n) {
        if(n>5000)return 1;
        vector<vector<double>>memo(n+1,vector<double>(n+1,-1.0));
        return solve(n,n,memo);
    }
};