class Solution {
public:
    bool check(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r])return 0;
            l++;r--;
        }
        return 1;

    }

    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                return check(s,l+1,r) or check(s,l,r-1);
            }
            l++;r--;
        }
        return 1;
    }
};

//  "asd n asdsaasd"