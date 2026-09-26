class Solution {
public:
    bool canTransform(vector<int>& s, vector<int>& t) {
        long long c=t[0],a=s[0];
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i==n-1)return c==a;
            if(a!=c){
                a=a+s[i+1]-c;
            }
            else a=s[i+1];
            c=t[i+1];
        }
        return 1;
    }
};