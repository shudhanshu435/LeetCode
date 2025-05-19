class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        unordered_map<long long,int>mp;
        set<vector<int>>s;
        vector<vector<int>>vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int m=j+1;m<n;m++){
                    mp[nums[m]]++;
                }
                for(int k=j+1;k<n;k++){
                    mp[nums[k]]--;
                    long long ss=(long long)nums[i]+(long long)nums[j]+(long long)nums[k];
                    long long num=target-ss;
                    if(mp[num]>0)s.insert({nums[i],nums[j],nums[k],(int)num});
                }
            }
        }
        for(auto it:s){
            vec.push_back(it);
        }
        return vec;
    }
};

/*


1 0 -1 0 -2 2
-2 -1 0 0 1 2



*/

