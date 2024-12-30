class Solution {
public:
    unordered_map<long long,long long>mp;
    long long solve(int len, int low, int high, int zero, int one){
        if(len>high)return 0;

        if(mp.find(len)!=mp.end())return mp[len];
        long long res;
        if(len>=low and len<=high)res=1;
        else res=0;

        res=(res+solve(len+zero,low,high,zero,one))%1000000007;
        res=(res+solve(len+one,low,high,zero,one))%1000000007;

        
        return mp[len]=res;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        return solve(0,low,high,zero,one);
    }
};