class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string s[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string>wos;
        
        for(int i=0;i<words.size();i++){
            string ss="";
            string ans=words[i];
            int m=words[i].size();
            for(int j=0;j<m;j++){
                ss+=s[ans[j]-97];
            }
            if(find(wos.begin(),wos.end(),ss)!=wos.end())
                 continue;
            else
            wos.push_back(ss);
        }
        // cout<<wos[0];
        return wos.size();
    }
};