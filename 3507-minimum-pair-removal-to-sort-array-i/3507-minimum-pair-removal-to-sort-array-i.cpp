class Solution {
public:
    bool sorted(vector<int>& nums){
        vector<int>v=nums;
        sort(v.begin(),v.end());
        return (v==nums);
    }
    int minimumPairRemoval(vector<int>& nums) {
        if(sorted(nums))return 0;
        int cnt=0;
        int n=nums.size();
        while(1){
            int sum=INT_MAX;
            cnt++;
            int ind;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<sum){
                    sum=nums[i]+nums[i+1];
                    ind=i;
                }
            }
            nums.erase(nums.begin()+ind);
            nums.erase(nums.begin()+ind);
            nums.insert(nums.begin()+ind,sum);
            // for(auto i:nums)cout<<i<<" ";
            // cout<<endl;
            if(sorted(nums))return cnt;
        }
        return n;
    }
};