class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length(),cnt=0;
        for(int i=0;i<26;i++){
            int f=-1,l=0;
            bool flag=1;
            for(int j=0;j<n;j++){
                if(s[j]==('a'+i) and flag==1){
                    f=j;
                    flag=0;
                }
                if(s[j]==('a'+i))l=j;
            }
            vector<bool>v(26,0);
            for(int k=f+1;k<l;k++){
                v[s[k]-'a']=1;
            }
            for(int kk=0;kk<26;kk++){
                if(v[kk]==1)cnt++;
            }
        }
        return cnt;
    }
};