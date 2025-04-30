class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0,c;
        for(auto i:nums){
            if(!((int)(log10(i)+1)&1))cnt++;
        }
        return cnt;

    }
};