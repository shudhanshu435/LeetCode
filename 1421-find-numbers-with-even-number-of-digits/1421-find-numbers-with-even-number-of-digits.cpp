class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0,c;
        for(auto i:nums){
            c=0;
            while(i){
                c++;
                i/=10;
            }
            if(!(c&1))cnt++;
        }
        return cnt;

    }
};