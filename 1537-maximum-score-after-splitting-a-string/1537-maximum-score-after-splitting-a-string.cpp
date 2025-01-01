class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int>l(n),r(n);
        int z=0,o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')z++;
            l[i]=z;
            if(s[n-1-i]=='1')o++;
            r[n-i-1]=o;
        }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,l[i]+r[i+1]);
        }
        return maxi;
    }
};