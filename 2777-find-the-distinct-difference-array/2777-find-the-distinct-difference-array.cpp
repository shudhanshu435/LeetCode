class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        vector<int>pref(n);
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            pref[i]=s.size();
        }
        s.clear();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=pref[i]-s.size();
            s.insert(nums[i]);
        }
        return ans;
    }
};