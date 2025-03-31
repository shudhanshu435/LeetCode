class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k)return 0;
        vector<long long>v(n-1);
        for(int i=0;i<n-1;i++){
            v[i]=(long long)weights[i]+(long long)weights[i+1];
        }
        long long ans=0;
        sort(v.begin(),v.end());
        for(int i:v)cout<<i<<" ";
        for(int i=0;i<k-1;i++){
            ans+=(v[n-2-i]-v[i]);
        }
        return ans;
    }
};