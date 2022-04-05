class Solution {
public:
    int maxArea(vector<int>& A) {
        int len=A.size();
        int p=0,q=len-1;
        int m;
        int maxi=0;
        while(p<q){
        m=min(A[p],A[q]);
        int area=m*(q-p);
        maxi=max(area,maxi);
        if(A[p]<A[q])p++;
        else q--;
    }return maxi;
    }
};
