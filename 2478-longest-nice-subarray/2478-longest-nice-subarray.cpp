class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // unordered_map<int,int>mp;
        long long sum=0,xorr=0;
        int k=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            xorr^=nums[i];
            if(xorr==sum){
                ans=max(ans,i-k+1);
            }
            else{
                while(xorr!=sum){
                    sum-=nums[k];
                    xorr^=nums[k];
                    k++;
                }
            }
        }
        return ans;
    }
};