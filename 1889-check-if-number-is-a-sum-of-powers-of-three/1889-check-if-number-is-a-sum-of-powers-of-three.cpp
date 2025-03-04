class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<long long>v;
        long long val=1;
        int i=0;
        while(val<=n){
            val=pow(3,i++);
            v.push_back(val);
        }
        int nn=v.size();
        long long sum=0;
        nn-=1;
        while(nn>=0){
            if(sum+v[nn]==n)return 1;
            else if(sum+v[nn]<n){
                sum+=v[nn];
                nn--;
            }
            else nn--;
        }
        return 0;
    }
};