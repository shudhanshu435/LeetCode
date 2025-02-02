class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        for(auto v:{'N','S'}){
            for(auto u:{'W','E'}){
                int rem=k,l=0,r=0;
                for(auto i:s){
                    if(i==v and rem){
                        if(i=='N')i='S';
                        else i='N';
                        rem--;
                    }
                    else if(i==u and rem){
                        if(i=='W')i='E';
                        else i='W';
                        rem--;
                    }
                    l+=(i=='E');
                    l-=(i=='W');
                    r+=(i=='N');
                    r-=(i=='S');
                    ans=max(ans,abs(l)+abs(r));
                }
            }
        }
        return ans;
    }
};