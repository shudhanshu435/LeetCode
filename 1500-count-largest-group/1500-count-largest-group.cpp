class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(int j=1;j<=n;j++){
            int i=j;
            int sum=0;
            while(i){
                sum+=(i%10);
                i/=10;
            }
            mp[sum]++;
            maxi=max(maxi,mp[sum]);
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second==maxi)cnt++;
        }
        return cnt;
    }
};