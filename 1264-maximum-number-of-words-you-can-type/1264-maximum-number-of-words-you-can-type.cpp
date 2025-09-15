class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>v(26,0);
        text+=' ';
        for(auto &i:brokenLetters){
            v[i-'a']=true;
        }
        bool b=0;
        int ans=0;
        for(auto &i:text){
            if(i!=' '){
                if(v[i-'a'])b=1;
            }
            else{
                if(!b)ans++;
                b=0;
            }
        }
        return ans;
    }
};