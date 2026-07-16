class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n),pref(n);
        mx[0]=nums[0];
        for(int i=1;i<n;i++)mx[i]=max(mx[i-1],nums[i]);
        for(int i=0;i<n;i++){
            pref[i]=__gcd(nums[i],mx[i]);
        }
        sort(pref.begin(),pref.end());

        long long sum=0;
        int i=0,j=n-1;
        while(i<j){
            sum+=__gcd(pref[i++],pref[j--]);
        }

        return sum;
    }
};