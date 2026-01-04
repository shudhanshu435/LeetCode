class Solution {
public:
    //checkprime
    bool is_prime(int n) {
        if(n<=1)return false;
        if(n<=3)return true;
        if(n%2==0 || n%3==0)return false;
        for(int i=5;i*i<=n;i+=6) {
            if(n%i==0 || n%(i+2)==0)return false;
        }
        return true;
    }

    //sieve
    vector<int>v;
    vector<bool>isPrime;
    void generateSieve(int limit) {
        isPrime.resize(limit+1,true);
        isPrime[0]=isPrime[1]=false;

        for(int i=2;i*i<=limit;++i) {
            if(isPrime[i]){
                for(int j=i*i;j<=limit;j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=limit;i++){
            if(isPrime[i])v.push_back(i);
        }
        
    }

    int sumFourDivisors(vector<int>& nums) {
        generateSieve(100000);
        // for(auto i:v)cout<<i<<" ";
        int sum=0;
        for(int &i:nums){
            if(i<=5)continue;
            int l=cbrt(i);
            // cout<<l<<endl;
            if(l*l*l==i){
                if(isPrime[l])sum+=1+l+l*l+l*l*l;
                continue;
            }
            for(int &j:v){
                if(i%j==0){
                    // cout<<i<<" "<<i/j<<endl;
                    if(j!=(i/j) and (isPrime[i/j])){
                        sum+=1+i+j+i/j;
                        // cout<<i<<" ee "<<endl;
                    }
                    break;
                }
            }
        }
        return sum;
    }
};