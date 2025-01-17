class Solution {
public:
    bool doesValidArrayExist(vector<int>& t) {
        int x=0;
        for(auto i:t)x^=i;
        return (x==0);
    }
};