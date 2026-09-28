class Solution {
public:
    int maxDepth(string s) {
        int mx=0,c=0;
        for(auto i:s){
            if(i=='(')c++;
            else if(i==')')c--;
            mx=max(mx,c);
        }
        return mx;
    }
};