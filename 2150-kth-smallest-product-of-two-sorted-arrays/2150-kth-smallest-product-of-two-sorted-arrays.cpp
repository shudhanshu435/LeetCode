class Solution {
public:
    // binary search on answer
    long long findcnt(vector<int>&nums1, vector<int>&nums2, long long midp){
        long long pr=0;
        int n=nums2.size();
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>=0){
                int l=0;
                int r=n-1;
                int m=-1;

                while(l<=r){
                    int mid=l+(r-l)/2;
                    long long prod=1ll*nums1[i]*nums2[mid];
                    if(prod<=midp){
                        m=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
                pr+=m+1;
            }
            else{
                int l=0;
                int r=n-1;
                int m=n;

                while(l<=r){
                    int mid=l+(r-l)/2;
                    long long prod=1ll*nums1[i]*nums2[mid];
                    if(prod<=midp){
                        m=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                pr+=(n-m);
            }
        }
        return pr;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long res=0;
        int n1=nums1.size();
        int n2=nums2.size();

        long long l=-1e10;
        long long h=1e10;

        while(l<=h){
            long long mid=l+(h-l)/2;
            long long csmall=findcnt(nums1,nums2,mid);

            if(csmall>=k){
                res=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};