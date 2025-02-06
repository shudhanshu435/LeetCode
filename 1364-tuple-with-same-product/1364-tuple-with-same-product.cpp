class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        long long ans=0;
        for(auto i:mp){
            int m=i.second;
            if(m>=2){
                ans+=(m*1ll*(m-1)*4);
            }
        }
        return ans;
    }
};