class Solution {
public:
    string largestGoodInteger(string num) {
        char ch='.';
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] and num[i+1]==num[i+2]){
                ch=max(ch,num[i]);
                i+=2;
            }
        }
        string s="";
        s+=ch;
        s+=ch;
        s+=ch;
        if(ch!='.')return s;
        return "";
    }
};