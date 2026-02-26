class Solution {
public:
    int numSteps(string s) {
        int onez=0;
        int n=s.size();
        while(s.back()=='0'){
            s.pop_back();
            onez++;
        }
        int z=0;
        if(n-onez>1){
            for(auto i:s)if(i=='0')z++;
            return z+1+n;
        }
        return onez;

    }
};