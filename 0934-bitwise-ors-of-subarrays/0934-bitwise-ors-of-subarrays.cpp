class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> s1, s2;
        s1.insert(nums[0]);
        s2.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            unordered_set<int>s;
            s.insert(nums[i]);
            for(auto &j:s1){
                s.insert(j|nums[i]);
            }
            s1=s;
            for(auto &k:s1)s2.insert(k);
        }
        return s2.size();
    }
};