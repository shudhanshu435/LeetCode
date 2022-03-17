class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int m=shifts.size();
        long long int sum=0;
        for(long long int i=0;i<m;i++)sum+=shifts[i];
        for(long long int i=0;i<m;i++){
            long long int r=sum%26;
            sum=sum-shifts[i];
            long long int g=int(s[i])-96;
            if((g+r)>26){
                r=r-26+g-1;
                s[i]='a'+r;
            }
            else
            s[i]=char(s[i]+r);
        }
        return s;
    }
};