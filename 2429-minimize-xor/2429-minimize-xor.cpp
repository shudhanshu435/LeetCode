class Solution {
public:
    unsigned int countBits(unsigned int n)
    {
       unsigned int count = 0;
       while (n)
       {
            count++;
            n >>= 1;
        }
        return count;
    }
    int minimizeXor(int num1, int num2) {
        int g=num1;
        string s="",ss="";
        int n1=__builtin_popcount(num1);
        int n2=__builtin_popcount(num2);
        if(n1==n2)return num1;
        while(num1){
                
             if(num1&1)s+='1';
             else s+='0';
             num1>>=1;
        }
        cout<<s<<endl;
        reverse(s.begin(),s.end());
        if(n1>n2){
            int cnt=1;
            for(int i=0;i<s.length();i++){
                if(s[i]=='1' && cnt<=n2){ss+='1';cnt++;}
                else ss+='0';
            }
        }
        else{
            cout<<n2<<endl;
            if(countBits(g)<n2){
                for(int i=0;i<n2;i++)ss+='1';
            }
            else{
                int cnt=1;
                reverse(s.begin(),s.end());
                for(int i=0;i<countBits(g);i++){
                    if(s[i]=='0' && cnt<=(n2-n1)){ss+='1';cnt++;}
                    else ss+=s[i];
                }
                reverse(ss.begin(),ss.end());

            }
        }
        cout<<ss<<endl;
        int value = bitset<64>(ss).to_ullong();
        return value;

    }
};