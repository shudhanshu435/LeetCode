class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
            int s=mpp[nums[i]].size(); 
            if(s>1){
                int sec=mpp[nums[i]][s-1];
                int fir=mpp[nums[i]][s-2];
                if(abs(fir-sec)<=k)return 1;
            }
        }
        return false;
    }
};