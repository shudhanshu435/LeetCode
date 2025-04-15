class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x1=0,x2=0;
        for(auto i:arr1)x1^=i;
        for(auto i:arr2)x2^=i;
        return x1&x2;
        // int n=arr1.size(),m=arr2.size();
        // vector<int>v(32,0),t(32,0);
        // for(int i=0;i<32;i++){
        //     int one=0;
        //     for(int j=0;j<n;j++){
        //         if((arr1[j]>>i)&1)one++;
        //     }
        //     v[i]=one;
        // }

        // for(int i=0;i<32;i++){
        //     int one=0;
        //     for(int j=0;j<m;j++){
        //         if((arr2[j]>>i)&1)one++;
        //     }
        //     t[i]=one;
        // }

        // long long ans=0;
        // for(int i=0;i<32;i++){
        //     if((v[i]*1ll*t[i])&1){
        //         ans+=(1ll<<i);
        //     }
        // }

        // return ans;
    }
};