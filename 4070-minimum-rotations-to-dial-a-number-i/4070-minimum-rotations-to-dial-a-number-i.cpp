class Solution {
public:
    int minRotations(string s) {
        int a=0,ans=0;
        for(auto i:s){
            int b=i-'0';
            ans+=min(abs(a-b),10-abs(a-b));
            a=b;
        }
        return ans;
    }
};