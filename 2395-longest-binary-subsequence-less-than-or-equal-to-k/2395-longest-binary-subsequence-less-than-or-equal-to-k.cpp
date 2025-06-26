class Solution {
public:
    long long bbc(string& binaryStr) {
        long long decimal = 0;
        long long power = 1;

        for (int i = binaryStr.length() - 1; i >= 0; --i) {
            if (binaryStr[i] == '1') {
                decimal += power;
            }
            power *= 2;
        }

        return decimal;
    }

    int longestSubsequence(string s, int k) {   
        int nk=k,cnt=0;
        while(nk){
            cnt++;
            nk/=2;
        }

        int n=s.length();
        if(n<cnt)return n;
        string ss="";
        for(int i=n-cnt;i<n;i++){
            ss+=s[i];
        }

        long long num=bbc(ss);
        // cout<<num<<endl;

        int z=0;
        for(int j=0;j<n-cnt;j++){
            if(s[j]=='0')z++;
        }
        if(num<=k)return z+cnt;
        return z+cnt-1;
        
    }
};