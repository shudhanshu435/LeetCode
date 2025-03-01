class Solution {
public:
    //this approach is correct but causing tle
    // vector<int>half(vector<int>&v){
    //     vector<int>vec;
    //     int num=0;
    //     int k=0;
    //     for(int i=0;i<v.size();i++){
    //         num=k*10+v[i];
    //         if(v[i]&1)k=1;
    //         else k=0;
    //         vec.push_back(num/2);
    //     }
    //     return vec;
    // }

    // int powMod(int a, vector<int>&b){
    //     long long int ans=1;
    //     while(b.size()>0 and b[0]!=0){
    //         int size=b.size();
    //         if(b[size-1]&1){
    //             ans=(ans*a)%1337;
    //             b[size-1]-=1;
    //         }
    //         else{
    //             a=(a*a)%1337;
    //             b=half(b);
    //         }
    //     }
    //     return ans;
    // }

    int powMod(int a, int e){
        long long ans=1;
        while(e){
            if(e&1){
                ans=(ans*a)%1337;
                e--;
            }
            else{
                long long c=(a*1ll*a)%1337;
                a=c;
                e/=2;
            }
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        // return powMod(a,b);
        int res=1;
        for(auto i:b){
            res=(powMod(res,10)*powMod(a,i))%1337;
        }
        return res;

    }
};