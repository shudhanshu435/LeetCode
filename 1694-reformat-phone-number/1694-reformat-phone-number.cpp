class Solution {
public:
    string reformatNumber(string number) {
        string s="";
        for(int i=0;i<number.length();i++){
         if(number[i]>='0'&& number[i]<='9')s+=number[i];
        }
        cout<<s<<endl;
        if(s.length()<=3)return s; 
        string ans="",str;
        while(s.length()!=0){
            if(s.length()>4){
                str=s.substr(0,3);
                ans+=str;
                ans+='-';
                s.erase(0,3);
            }
            else if(s.length()==4){
                str=s.substr(0,2);
                ans+=str;
                ans+='-';
                str=s.substr(2,4);
                ans+=str;
                s.erase(0,4);
            }
            else
            {
                ans+=s;
                s.erase();
            }
        }
        return ans;
        
    }
};