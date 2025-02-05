class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return 1;
        int p1=-1,p2=-1,cnt=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(p1==-1)p1=i;
                p2=i;
                cnt++;
            }
        }
        if(cnt!=2)return 0;
        if(s1[p1]==s2[p2] and s2[p1]==s1[p2])return 1;
        return 0;
    }
};