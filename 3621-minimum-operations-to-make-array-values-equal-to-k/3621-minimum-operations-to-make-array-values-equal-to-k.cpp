class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>s;
        int mini=101;
        for(auto i:nums){
            s.insert(i);
            mini=min(mini,i);
        }
        int size=s.size();
        if(k>mini)return -1;
        if(k==mini)return size-1;
        return size;
    }
};