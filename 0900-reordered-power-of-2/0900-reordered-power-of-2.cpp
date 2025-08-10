class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());

        for(int i=0;i<32;i++){
            int m=(1<<i);
            string ss=to_string(m);
            sort(ss.begin(),ss.end());
            if(s==ss)return 1;
        }
        return 0;
    }
};