class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            int ss=0;
            int m=k;
            string ans="";
            for(auto i:s){
                m--;
                ss+=(i-'0'); 
                if(m==0){
                    m=k;
                    ans+=to_string(ss);
                    ss=0;
                }
            }
            if(m!=k)ans+=to_string(ss);
            // cout<<ans<<endl;
            s=ans;
        }
        return s;
    }
};