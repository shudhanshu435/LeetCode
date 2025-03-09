class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int carry=0;
        while(i>=0 and j>=0){
            if(a[i]==b[j]){
                if(carry==1)ans+='1';
                else ans+='0';
                if(a[i]=='1')carry=1;
                else carry=0;
            }
            else{
                if(carry==1)ans+='0';
                else ans+='1';
            }
            i--;j--;
        }
        while(i>=0){
            if(carry==(a[i]-'0')){
                if(carry==1)ans+='0';
                else{
                    ans+='0';carry=0;
                }
            }
            else{
                ans+='1';
                carry=0;
            }
            i--;
        }
        while(j>=0){
            if(carry==(b[j]-'0')){
                if(carry==1)ans+='0';
                else{
                    ans+='0';carry=0;
                }
            }
            else{
                ans+='1';
                carry=0;
            }
            j--;
        }
        if(carry==1)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};