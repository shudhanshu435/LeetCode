class Solution {
public:
    int singleNumber(vector<int>& arr) {
        long long ans=0,nn=0;
        bool neg=false;
        for(int i=0;i<32;i++){
            int one=0;
            for(int i=0;i<arr.size();i++){
                if(arr[i]&1)one++;
                if(!neg)
                    if(arr[i]<0)nn++;
                arr[i]/=2;
            }
            if(nn%3!=0)neg=true;
            if(one%3!=0)ans+=(1<<i);
        }
        if(neg)return -ans;
        return ans;
    }
};