class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=0;
        for(int i:left)l=max(l,i);
        for(int i:right)l=max(l,n-i);
        return l;
    }
};