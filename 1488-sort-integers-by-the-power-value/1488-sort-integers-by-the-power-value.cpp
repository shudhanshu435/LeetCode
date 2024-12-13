class Solution {
public:
    #define p pair<int,int>
    int recurr(int lo, unordered_map<int,int>&dp){
        if(lo==1)return 0;

        if(dp.count(lo))return dp[lo];

        if(lo&1) return dp[lo]=1+recurr(lo*3+1,dp);
        else return dp[lo]=1+recurr(lo/2,dp);

    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>>pq;
        unordered_map<int,int>dp;
        for(int i=lo;i<=hi;i++){
            int ind=recurr(i,dp);
            pq.push_back({ind,i});
        }
        int n=pq.size();
        for(auto pp:pq){
            cout<<pp[0]<<" "<<pp[1]<<endl;
        }
        sort(pq.begin(),pq.end()); 
        return pq[k-1][1];
        
    }
};

/*

9  9  17 17
12 13 14 15

*/