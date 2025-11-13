class Solution {
public:
    int maxOperations(string s) {
        int z=0,one=0,ans=0,b=1;
        while(!s.empty()){
            if(s.back()=='1'){
                one++;
                b=1;
            }
            else if(b){
                ans+=(one*z);
                z++;
                one=0;
                b=0;
            }
            s.pop_back();
        }
        ans+=one*z;
        return ans;
    }
};
