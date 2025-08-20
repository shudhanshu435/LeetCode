class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto i:nums)x=x^i;
        int pos=0;
        while(x%2==0){
            x>>=1;
            pos++;
        }
        // cout<<pos<<endl;
        int a=0,b=0;
        for(auto i:nums){
            if((i&(1<<pos)))a=a^i;
            else b=b^i;
        }
        return {min(a,b),max(a,b)};
    }
};