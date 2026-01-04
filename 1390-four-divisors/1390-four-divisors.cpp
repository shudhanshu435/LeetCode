class Solution {
public:
    int cnt(int n){
        int i=2;
        if(n<=5)return 0;
        int sum=1+n;
        int cnt=0;
        for(;i*i<=n;i++){
            if(n%i==0){
                if(i==(n/i))return 0;
                sum+=i+(n/i);
                cnt++;
            }
            if(cnt>=2)return 0;
        }
        return (cnt==1)?sum:0;
    }

    int sumFourDivisors(vector<int>& nums) {
        // generateSieve(100000);
        // for(auto i:v)cout<<i<<" ";
        int sum=0;
        for(auto &i:nums)sum+=cnt(i);
        return sum;
        // int sum=0;
        // for(int &i:nums){
        //     if(i<=5)continue;
        //     int l=cbrt(i);
        //     // cout<<l<<endl;
        //     if(l*l*l==i){
        //         if(isPrime[l])sum+=1+l+l*l+l*l*l;
        //         continue;
        //     }
        //     for(int &j:v){
        //         if(i%j==0){
        //             // cout<<i<<" "<<i/j<<endl;
        //             if(j!=(i/j) and (isPrime[i/j])){
        //                 sum+=1+i+j+i/j;
        //                 // cout<<i<<" ee "<<endl;
        //             }
        //             break;
        //         }
        //     }
        // }
        // return sum;
    }
};