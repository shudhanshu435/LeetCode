class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        string ans="";
        unordered_map<string,string>mp;
        for(auto i:know){
            mp[i[0]]=i[1];
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                i++;
                string c="";
                while(s[i]!=')'){
                    c+=s[i];
                    i++;
                }
                // cout<<c<<endl;
                if(mp.find(c)!=mp.end())ans+=mp[c];
                else ans+='?';
            }
            else ans+=s[i];
        }
        return ans;
    }
};