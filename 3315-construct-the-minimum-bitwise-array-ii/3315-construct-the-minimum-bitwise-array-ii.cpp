class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            if(i==2)ans.push_back(-1);
            else{
                long long x=i;
                int aa=0;
                int j;
                for(j=0;j<32;j++){
                    if((x&(1<<j)) and (x&(1<<(j+1)))){
                        // cout<<'d';
                        aa+=(1<<j);
                    }
                    else{
                        break;
                    }
                }
                j++;
                for(;j<32;j++){
                    if((x>>j)&1){
                        aa+=(1<<j);
                    }
                }
                ans.push_back(aa);
            }
        }
        return ans;
    }
};