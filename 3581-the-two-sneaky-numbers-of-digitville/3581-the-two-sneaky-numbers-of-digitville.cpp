class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>vec(101,0);
        for(auto &i:nums)vec[i]++;
        int a=-1,b;
        for(int i=0;i<101;i++){
            if(vec[i]==2){
                if(a==-1)a=i;
                else {
                    b=i;
                    break;
                }
            }
        }
        return {a,b};
    }
};