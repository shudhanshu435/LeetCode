class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n+1,0);
        for(auto q:queries){
            v[q[0]]+=1;
            v[q[1]+1]-=1;
        }
        for(int i=1;i<v.size();i++){
            v[i]=v[i]+v[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]-v[i]>0)return 0;
        }
        return 1;
    }
};