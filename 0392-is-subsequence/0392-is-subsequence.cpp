class Solution {
public:
    bool isSubsequence(string a, string b) {
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]){
                i++;j++;
            }
            else j++;
        }
        if(i!=a.size())return 0;
        return 1;
    }
};