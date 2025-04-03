class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<long long>fm(n);
        vector<long long>sm(n);
        fm[0]=nums[0];
        sm[n-1]=nums[n-1];
        for(int i=0;i<n-1;i++){
            fm[i+1]=max((long long)nums[i+1],fm[i]);
            sm[n-2-i]=max((long long)nums[n-2-i],sm[n-1-i]);
        }
        for(int i=1;i<n-1;i++){
            ans=max(ans,(fm[i-1]-nums[i])*sm[i+1]);
        }
        return ans;
    }
};