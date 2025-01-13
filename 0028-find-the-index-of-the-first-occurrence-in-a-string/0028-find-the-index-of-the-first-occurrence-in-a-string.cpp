class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();
        bool found=false;
        for(int i=0;i<m;i++){
            int j;
            for(j=0;j<n;){
                if(needle[j]==haystack[i+j]){
                    j++;
                }
                else break;
            }
            if(j==n)return i;
        }
        return -1;
    }
};