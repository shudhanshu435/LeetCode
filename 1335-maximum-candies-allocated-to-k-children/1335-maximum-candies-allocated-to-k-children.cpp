class Solution {
public:
    bool pos(vector<int>&vec, long long mid, long long k){
        long long cnt=0;
        for(int i=0;i<vec.size();i++){
            cnt+=(vec[i]/mid);
            if(cnt>=k)return 1;
        }
        return 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(),candies.end(),0ll);
        if(sum<k)return 0;
        int n=candies.size();
        int m=sum/k;
        int i=1,j=m;
        int ans=0;
        sort(candies.rbegin(),candies.rend());
        while(i<=j){
            int mid=j-(j-i)/2;
            if(pos(candies,mid,k)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};