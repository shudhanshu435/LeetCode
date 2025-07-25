class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        if(name[0]!=typed[0])return 0;
        while(i<name.size() and j<typed.size()){
            if(name[i]==typed[j]){
                i++;j++;
            }
            else {
                if(j-1>=0 and typed[j]!=typed[j-1])return 0;
                j++;
            }
        }
        if(i!=name.size())return 0;
        while(j<typed.size()){
            if(j-1>=0 and typed[j]!=typed[j-1])return 0;j++;
        }
        return 1;
    }
};