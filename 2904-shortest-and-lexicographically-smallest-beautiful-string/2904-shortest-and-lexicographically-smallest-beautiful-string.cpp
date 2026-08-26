class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len=s.length();
        string ans="";
        for(int i=0;i<len;i++){
            int count=0;
            string curr="";
            for(int j=i;j<len;j++){
                curr+=s[j];
                count+=(s[j]=='1');
                if(count==k){
                    if(ans.size() == curr.size()) ans = min(ans,curr);
                    else if(ans.size() > curr.size()) ans = curr;
                    else if(ans.size() == 0) ans = curr;
                }
            }
        }
        return ans;
    }
};