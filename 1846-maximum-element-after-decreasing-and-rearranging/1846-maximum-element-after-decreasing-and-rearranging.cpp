class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n==1)return 1;
        long long ans=0;
        long long prev=1;
        for(int i=1;i<n;i++){
            prev=min(prev+1,(long long)arr[i]);
            ans=max(ans,prev);
        }
        return (int)ans;
    }
};