class Solution {
public:
    bool isValid(string word) {
        int ch=0,v=0,cc=0;
        for(auto i:word){
            if(!isalpha(i) and !isdigit(i)){
                return 0;
            }
            ch++;
            if(i=='A' or i=='E' or i=='I' or i=='O' or i=='U' or i=='a' or i=='e' or i=='i' or i=='o' or i=='u')v++;
            else if(isalpha(i))cc++;
        }
        if(ch>=3 and v>0 and cc>0)return 1;
        return 0;
    }
};