class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int>diff;
        if(n<3)return 0;
        for(int i=1;i<n;i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        int cnt=1;
        // for(auto i:diff)cout<<i<<" ";
        for(int i=1;i<diff.size();i++){
            if(diff[i]==diff[i-1]){
                cnt++;
            }
            else{
                ans+=(cnt*(cnt-1)/2);
                cnt=1;
            }
        }
        ans+=(cnt*(cnt-1)/2);
        return ans;
    }
};