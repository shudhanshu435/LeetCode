class Solution {
public:
    // long long binS(long long l, long long r, vector<long long>&pref, long long k){
    //     long long b=l;
    //     if(l==0){
    //         while(l<=r){
    //             int mid=l+(r-l)/2;
    //             if(pref[mid]*1ll*(mid+1)<k)l=mid+1;
    //             else r=mid-1;
    //         }
    //         return r+1-b;
    //     }
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         if((pref[mid]-pref[b-1])*1ll*(mid+1-b)<k)l=mid+1;
    //         else r=mid-1;
    //     }
    //     return r+1-b;
    // }  
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        // vector<long long>pref(n);
        // pref[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     pref[i]=nums[i]+pref[i-1];
        // }
        // long long s=0,ans=0;
        // for(int i=0;i<n;i++){
        //     s=binS(i,n-1,pref,k);
        //     // cout<<s<<endl;
        //     ans+=s;
        // }
        // return ans;

        //////// sliding window approach
        long long s=0,c=0,l=0,ans=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            c++;
            while(s*1ll*(i-l+1)>=k){
                s-=nums[l];
                l++;
                c--;
            }
            ans+=c;
        }
        return ans;

    }
};

/*

  2  1  4  3   5
- 2  3  7  10  15
  15 13 12  8  5 -

*/

