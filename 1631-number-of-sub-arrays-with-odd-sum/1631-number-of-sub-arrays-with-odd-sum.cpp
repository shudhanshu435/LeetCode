class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<long long>v(n,0);
        v[0]=arr[0];
        int ev=0,od=0;     
        if(v[0]&1)od++;
        else ev++;         
        for(int i=1;i<arr.size();i++){
            v[i]=v[i-1]+arr[i];
            if(v[i]&1)od++;
            else ev++;
        }
        cout<<od<<" "<<ev<<endl;
        long long ans=od;
        for(int i=0;i<n-1;i++){
            if(arr[i]&1){
                od--;
                swap(ev,od);
            }
            else ev--;
            if(od>=0)
            ans=(ans+od)%1000000007;
        }
        return ans;

    }
};