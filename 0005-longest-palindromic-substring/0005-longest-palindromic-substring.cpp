class Solution {
public:
    string longestPalindrome(string s) {
        int i=0,j=0;
        // for odd length
        int n=s.length();
        string ans="";
        int curr=0;
        int nn=n;
        int k=1;
        while(nn--){
            curr=0;
            while(i>=0 and j<=n and s[i]==s[j]){
                curr++;
                i--;
                j++;
            }
            i++;
            j--;
            // cout<<i<<" "<<j<<endl;
            string ss=s.substr(i,j-i+1);
            if(ss.length()>ans.length())ans=ss;
            i=j=(k++);
        }

        nn=n-1;
        i=0;
        j=1;
        k=1;
        while(nn--){
            curr=0;
            while(i>=0 and j<=n and s[i]==s[j]){
                curr++;
                i--;
                j++;
            }
            i++;
            j--;
            // cout<<i<<" "<<j<<endl;
            string ss=s.substr(i,j-i+1);
            if(ss.length()>ans.length())ans=ss;
            i=k;
            j=k+1;
            k++;
        }
        

        return ans;
        
    }
};