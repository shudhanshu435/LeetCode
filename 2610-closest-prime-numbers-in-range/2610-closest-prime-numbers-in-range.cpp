class Solution {
public:
    vector<int> Sieve(int n){
        vector<bool>isPrime(n+1,true);
        vector<int>prime;
        isPrime[0]=isPrime[1]=false;

        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(isPrime[i]==true)prime.push_back(i);
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        if(left==right)return {-1,-1};
        vector<int>v=Sieve(right);
        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;
        auto it=lower_bound(v.begin(),v.end(),left);
        int index=it-v.begin();
        // cout<<index<<endl;
        int diff=INT_MAX;
        int a=-1,b=-1;
        for(int i=index;i<v.size()-1;i++){
            if((v[i+1]-v[i]) < diff){
                a=v[i];b=v[i+1];
                diff=(v[i+1]-v[i]);
            }
        }
        return {a,b};
    }
};