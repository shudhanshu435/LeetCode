class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        if(n<m)return 0;
        int k=0,cnt=0;
        int j;
        for(int i=0;i<m;i++){
            char ch=str2[i];
            for(j=k;j<n;j++){
                char c=str1[j];
                char c1;
                if(c=='z')c1='a';
                else c1=c+1;
                if(ch==c or ch==c1){
                    k=j+1;
                    break;
                    cnt++;
                }
            }
            if(j==n)return 0;

        }
        return 1;
    }
};