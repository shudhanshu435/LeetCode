class Solution {
public:
    string reformatDate(string date) {
        string ans="",a,b;
        string s[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string ss[]={"01","02","03","04","05","06","07","08","09","10","11","12"};
        
        reverse(date.begin(),date.end());
        a=date.substr(0,4);
        reverse(a.begin(),a.end());
        reverse(date.begin(),date.end());
        ans+=a;
        ans+="-";
        a.clear();
        
        for(int i=0;i<date.length();i++){
            if(date[i]==' '){
                a=date.substr(i+1,3);
                break;
            }
        }
        int cnt=0;
        for(int i=0;i<12;i++){
            if(s[i]==a){
                cnt=i;
                break;
            }
        }
        ans+=ss[cnt];
        ans+='-';
        a.clear();
        for(int i=0;i<date.length();i++){
            if(date[i]>='0' && date[i]<='9')a+=date[i];
            else break;
        }
        if(a.length()==1){
        ans+="0";
        ans+=a;}
        else ans+=a;
        
        
        
        return ans;
    }
};