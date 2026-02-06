class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // 1 3 40 43 44 
        int maxi=0;
        int n=nums.size();
        if(n==1)return 0;
        int i=0,j=0;
        while(j<n){
            if(nums[i]*1ll*k < 1ll*nums[j]){
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        // cout<<maxi<<endl;
        return n-maxi;
    }
};
