class Solution {
public:
    int mod=1000000007;
    int func(int n){
        long long fact=1;
        for(int i=n;i>=1;i--){
            fact=(fact*i)%mod;
        }
        return fact;
    }
    int countPermutations(vector<int>& cc) {
        int mini=*min_element(cc.begin(),cc.end());
        int cnt=count(cc.begin(),cc.end(),mini);
        cout<<cnt<<endl;
        int n=cc.size();
        if(cc[0]!=mini or cnt>1)return 0;
        return func(n-1);
        return 0;
    }
};