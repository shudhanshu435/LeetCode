class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
        for(auto i:nums)s.insert(i);
        int mini=*s.begin();
        int size=s.size();
        if(k>mini)return -1;
        if(k==mini)return size-1;
        return size;
    }
};