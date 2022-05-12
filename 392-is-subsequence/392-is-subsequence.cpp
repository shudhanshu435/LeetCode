class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len=s.length();
        int cnt=0,k=0;
        for(int i=0;i<len;i++){
            for(int j=k;j<t.length();j++){
                if(s[i]==t[j])
                {
                    cnt++;
                    k=j+1;
                    break;
                    
                }
                if(cnt==len)break;
            }
        }
        cout<<cnt<<endl;
        if(cnt==len)return 1;
        else return 0;
    }
};
