class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss=s;
        int len=s.length(),ans=0;
        for(int i=0;i<len;i++){
            rotate(s.begin(), s.begin()+i, s.end());
            if(s==goal){
                ans++;
                break;
            }
            s=ss;

        }
        if(ans==0)return 0;
        else return 1;
    }
};