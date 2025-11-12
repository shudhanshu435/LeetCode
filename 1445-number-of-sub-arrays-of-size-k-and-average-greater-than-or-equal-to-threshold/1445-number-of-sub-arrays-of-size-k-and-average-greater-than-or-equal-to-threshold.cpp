class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int i=0,sum=0;
        int n=arr.size();
        for(;i<k;i++){
            sum+=arr[i];
        }
        int cnt=0,s=0;
        if(sum>=th*k)cnt++;
        for(;i<n;i++){
            sum-=arr[s++];
            sum+=arr[i];
            if(sum>=th*k)cnt++;
        }
        return cnt;
    }
};