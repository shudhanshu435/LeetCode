class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        for(int i=1;i<=n;i++)ans+=(i+'0');
        k--;
        while(k--){
            next_permutation(ans.begin(),ans.end());
        }
        return ans;
    }
};