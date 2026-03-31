class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        string ans(n + m - 1, '?');
        unordered_set<int> st;

        for(int i=0; i<n; i++) {
            if(str1[i] == 'T') {
                int j = i, ct = 0;
                while(ct < m) {
                    if(ans[j] != '?' && ans[j] != str2[ct]) {
                        return "";
                    }
                    ans[j] = str2[ct];
                    st.insert(j);
                    j++; ct++;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(str1[i] == 'F') {
                int j = i, ct = 0;
                while(ct < m) {
                    if(ans[j] == '?') ans[j] = 'a';
                    j++; ct++;
                }
                if(i + m <= ans.size()) {
                    string sub = ans.substr(i, m);
                    if(sub == str2) {
                        bool ok = false;
                        ct--; j--;
                        while(ct >= 0) {
                            if(!st.count(j)) {
                                ans[j] = 'b';
                                ok = true;
                                break;
                            }
                            j--; ct--;
                        }
                        if(!ok) return "";
                    }
                }
            }
        }
        return ans;
    }
};