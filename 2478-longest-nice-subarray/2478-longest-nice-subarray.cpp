class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // unordered_map<int,int>mp;
        vector<int>vec(32,0);
        int ans=1;
        int k=0;
        for(int i=0;i<nums.size();i++){
            bool nice=1;
            for(int j=0;j<32;j++){
                if((nums[i]>>j)&1)vec[j]++;
                if(vec[j]==2){
                    nice=0;
                }
            }
            if(nice)ans=max(ans,i-k+1);
            else{
                while(1){
                    int cnt=0;
                    for(int j=0;j<32;j++){
                        if((nums[k]>>j)&1)vec[j]--;
                        if(vec[j]<=1){
                            cnt++;
                        }
                    }
                    k++;
                    if(cnt==32)break;
                }
            }
        }
        return ans;
    }
};