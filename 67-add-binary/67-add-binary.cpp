class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int t=max(a.length(),b.length());
        int k=a.length();
        int m=b.length();
        while(k++<m)a.append("0");
        while(m++<k)b.append("0");
        int i=0;
        while(t){
            if(a[i]=='1'&& b[i]=='1'){
                if(carry==0){
                    ans+= "0";
                    carry=1;
                }
                else{
                    ans+= "1";
                    carry=1;
                }
            }
            else if((a[i]=='0'||a[i]==' ') && (b[i]=='0'||b[i]==' ')){
                if(carry==0){
                    ans+= "0";
                    carry=0;
                }
                else{
                    ans+= "1";
                    carry=0;
                }
            }
            else{
                if(carry==0){
                    ans+= "1";
                    carry=0;
                }
                else{
                    ans+= "0";
                    carry=1;
                }
            }
            t--;
            i++;
            
        }
        if(carry==1)ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};