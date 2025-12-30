class Solution {
public:
    int kpp(vector<int> &a, vector<int> &b, int k) {
            // code here
        int m=a.size(),n=b.size();
        if (m > n) return kpp(b, a, k);
        if(a[m-1]<=b[0]){
            if(k<=m)return a[k-1];
            else return b[k-m-1];
            // cout<<"ss";
        }
        else if(b[n-1]<=a[0]){
            if(k<=n)return b[k-1];
            else return a[k-n-1];
            // cout<<"ss";
        }
        
        if(m>=k){
            if(a[k-1]<=b[0])return a[k-1];
        }
        if(n>=k){
            if(b[k-1]<=a[0])return b[k-1];
        }
        
        int ans=0;
        int l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            int xmid=k-mid-2;
            if (xmid >= n) {
                l = mid + 1;
                continue;
            }
            if (xmid < 0) {
                r = mid - 1;
                continue;
            }
            
            if((xmid+1)<n and b[xmid+1]<a[mid]){
                r=mid-1;
            }
            else if((mid+1)<m and a[mid+1]<b[xmid]){
                l=mid+1;
            }
            else{
                ans=max(a[mid],b[xmid]);
                break;
            }
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        if(n==0){
            if(m&1)return b[m/2];
            else return (b[m/2]+b[(m/2)-1])/2.0;
        }
        else if(m==0){
            if(n&1)return a[n/2];
            else return (a[n/2]+a[(n/2)-1])/2.0;
        }
        int k=(n+m)/2+1;
        if((n+m)%2!=0){
            return kpp(a,b,k);
        }
        else{
            return (kpp(a,b,k)+kpp(a,b,k-1))/2.0;
        }
    }
};