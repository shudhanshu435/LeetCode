class Solution {
public:
    int strStr(string haystack, string needle) {
        string s="";
        int len=needle.length(),ans=-1;
        if(len>haystack.length())return ans;
        for(int i=0;i<=haystack.length()-len;i++){
            s=haystack.substr(i,len);
            if(s==needle){ans=i;break;}
        }
        return ans;
    }
};