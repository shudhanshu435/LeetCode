class Solution {
public:
    string dd(string &s, int k) {
        int n=s.length();
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                cnt++;
                if(cnt==k)return string(1,s[i]);
            }
            else{
                long long c=cnt;
                cnt=cnt*1ll*(s[i]-'0');
                if(cnt>=k)return dd(s,k-c);
            }
        }
        return "";
    }
    string decodeAtIndex(string s, int k) {
        return dd(s,k);
    }
};