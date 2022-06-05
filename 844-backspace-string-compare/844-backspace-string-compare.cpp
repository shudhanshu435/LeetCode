class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i;
        for(i=0; i<s.size();)
        {
            if(s[i]=='#')
            {
                if(i!=0){
                    s.erase(s.begin()+i);
                    i--;
                    s.erase(s.begin()+i);
                }
                else s.erase(s.begin()+i);
            }
            else i++;
            
        }
        for(i=0; i<t.size();)
        {
            if(t[i]=='#')
            {
                if(i!=0){
                    t.erase(t.begin()+i);
                    i--;
                    t.erase(t.begin()+i);
                }
                else t.erase(t.begin()+i);
            }
            else
                i++;
            
        }
        if(s==t)return 1;
        else return 0;
        
    }
};