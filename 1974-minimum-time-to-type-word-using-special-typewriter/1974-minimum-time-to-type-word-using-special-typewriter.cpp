class Solution {
public:
    int minTimeToType(string word) {
        char c='a';
        int m,t=0;
        for(int i=0;i<word.length();i++){
            m=abs(c-word[i]);
            if(m>13)
            t+=26-abs(m);
            else t+=m;
            c=word[i];
            
        }
        return t+word.length();
    }
};