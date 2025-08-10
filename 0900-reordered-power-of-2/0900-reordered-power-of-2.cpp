class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int>mp;
        while(n){
            mp[n%10]++;
            n/=10;
        }
        long long p=0;
        for(int i=0;i<32;i++){
            unordered_map<int,int>mp2;
            int m=(1<<i);
            while(m){
                mp2[m%10]++;
                m/=10;
            }
            int cnt=0;
            if(mp==mp2)return 1;
        }
        return 0;
    }
};