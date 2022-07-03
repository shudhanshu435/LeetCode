class Solution {
public:
    string decodeMessage(string key, string message) {
        string ss="abcdefghijklmnopqrstuvwxyz";
        string s="";
        for(int i=0;i<key.length();i++){
            if(key[i]!=' '){
            char c=key[i];
            size_t found = s.find(c);
            if (found != string::npos)
                continue;
            else 
                s+=c;
            }
        }
        string ans="";
        for(int i=0;i<message.length();i++){
            if(message[i]==' ')ans+=' ';
            else{
            char ch=message[i];
            size_t found = s.find(ch);
            ans+=ss[found];
            }
            
        }
        
        return ans;
    }
};