class Solution {
public:
    bool scoreBalance(string s) {
        int sum=0;
        for(char c:s){
            sum+=(c-'a'+1);
        }
        int sum1=0;
        for(int i=0;i<s.length();i++){
            sum1+=s[i]-'a'+1;
            sum-=s[i]-'a'+1;
            if(sum1==sum)return 1;
        }
        return 0;
    }
};