class Solution {
public:
//1 2 3 4
//1 2 6
//24 12 4
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n-1,1),suff(n-1,1);
        pref[0]=nums[0];
        suff[n-2]=nums[n-1];
        for(int i=1;i<n-1;i++){
            pref[i]=nums[i]*pref[i-1];
            suff[n-2-i]=nums[n-i-1]*suff[n-1-i];
        }
        vector<int>ans;
        ans.push_back(suff[0]);
        for(int i=0;i<n-2;i++){
            ans.push_back(pref[i]*suff[i+1]);
        }
        ans.push_back(pref[n-2]);
        return ans;
    }
};