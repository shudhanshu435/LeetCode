// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n;
        while(l<=r){
            long long mid=(l+r)/2;
            if(isBadVersion(mid)==false)l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};


// 1 2 3 4 5