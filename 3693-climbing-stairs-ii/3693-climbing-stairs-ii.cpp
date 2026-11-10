class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>v(n,0);
        v[0]=costs[0]+1;
        if(n>=2)v[1]=min(v[0]+costs[1]+1,costs[1]+4);
        if(n>=3)v[2]=min({costs[2]+9,costs[2]+v[1]+1,costs[2]+v[0]+4});
        for(int i=3;i<n;i++){
            v[i]=min({costs[i]+v[i-3]+9, costs[i]+v[i-2]+4, costs[i]+v[i-1]+1});
        }
        return v[n-1];
    }
};