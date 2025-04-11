class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string a=to_string(i);
            int n=a.length();
            if(n&1)continue;
            if(accumulate(a.begin(),a.end()-n/2,0) == accumulate(a.begin()+n/2, a.end(),0))cnt++;
        }
        return cnt;
    }
};