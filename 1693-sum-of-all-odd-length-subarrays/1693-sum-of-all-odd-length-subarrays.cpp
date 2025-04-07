class Solution {
public:
    int func(vector<int>&arr, int len){
        int sum=0;
        if(len==1){
            sum=accumulate(arr.begin(),arr.end(),0);
            return sum;
        }
        int curr=0;
        for(int i=0;i<len;i++){
            curr+=arr[i];
        }
        sum+=curr;
        int k=0;
        for(int i=len;i<arr.size();i++){
            curr=curr-arr[k++]+arr[i];
            sum+=curr;
        }

        return sum;
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=1;i<=arr.size();i+=2){
            ans+=func(arr,i);
        }
        return ans;
    }
};