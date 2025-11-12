class Solution {
public:
    int minOperations(vector<int>& nums) {
        int mini=INT_MAX;
        int n=nums.size(),one=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x==1)one++;
            for(int j=i;j<n;j++){
                x=__gcd(x,nums[j]);
                if(x==1){
                    mini=min(mini,j-i+1);
                    break;
                }
            }
        }
        // cout<<mini;
        if(one)return n-one;
        return (mini!=INT_MAX)?(mini-1+n-1):-1;
    }
};