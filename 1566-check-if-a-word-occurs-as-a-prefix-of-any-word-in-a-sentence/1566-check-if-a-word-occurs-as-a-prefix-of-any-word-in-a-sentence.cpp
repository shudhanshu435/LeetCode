class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string s;
        int size=searchWord.length();
        int i=1;
        while(ss>>s){
            if(s.size()>=size and s.substr(0,size)==searchWord)return i;
            i++;
        }
        return -1;
    }
};