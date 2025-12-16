class Solution {
public:
    vector<int> kmp(string txt, string pat) {
        int n = txt.size(), m = pat.size();
        vector<int> lps(m, 0);

        for (int i = 1, len = 0; i < m; ) {
            if (pat[i] == pat[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }

        vector<int> res;
        for (int i = 0, j = 0; i < n; ) {
            if (txt[i] == pat[j]) {
                i++; j++;
            }
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                if (j) j = lps[j - 1];
                else i++;
            }
        }
        return res;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ind,rnd;
        int n=s.length();
        int aa=a.length();
        int bb=b.length();
        ind=kmp(s,a);
        rnd=kmp(s,b);
        //a - 16 , 33
        //b - 0 , 18
        int i=0,j=0;
        for(auto i:ind)cout<<i<<" ";
        cout<<endl;
        for(auto i:rnd)cout<<i<<" ";
        cout<<endl;

        vector<int>ans;
        while(i<ind.size() and j<rnd.size()){
            if(abs(ind[i]-rnd[j])<=k)ans.push_back(ind[i++]);
            else{
                if(ind[i]>rnd[j])j++;
                else i++;
            }
        }
        return ans;
    }
};