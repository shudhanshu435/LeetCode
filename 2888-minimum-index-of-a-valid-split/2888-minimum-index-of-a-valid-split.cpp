class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int dom;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>n/2){
                dom=i;
            }
        }
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(nums[i]==dom){
                l++;
            }
            r=mp[dom]-l;
            // cout<<l<<" "<<r<<endl;
            if(l>(i+1)/2 and r>(n-i-1)/2)return i;
        }
        return -1;

    }
};