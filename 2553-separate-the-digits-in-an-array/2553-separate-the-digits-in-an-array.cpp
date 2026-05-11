class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums){
            string s=to_string(i);
            for(auto a:s){
                v.push_back(a-'0');
            }
        }
        return v;
    }
};