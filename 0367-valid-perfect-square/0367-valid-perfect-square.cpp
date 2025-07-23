class Solution {
public:
    bool isPerfectSquare(int x) {
        int l=1,r=x;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid==x/mid and x%mid==0)return true;
            if(mid<x/mid)l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};