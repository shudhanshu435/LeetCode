class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long>s;
        for(auto i:nums){
            if(s.empty())s.push(i);
            else{
                int t=s.top();
                int g=__gcd(t,i);
                if(g!=1){
                    s.pop();
                    s.push((t*1ll*i)/g);
                    while(s.size()>=2){
                        int t1=s.top();
                        s.pop();
                        int t2=s.top();
                        int gg=__gcd(t1,t2);
                        if(gg!=1){
                            s.pop();
                            s.push((t1*1ll*t2)/gg);
                        }
                        else{
                            s.push(t1);
                            break;
                        }
                    }
                }
                else s.push(i);
            }
        }
        int size=s.size();
        vector<int>v(size,0);
        while(!s.empty()){
            v[size-1]=s.top();
            s.pop();
            size--;
        }
        return v;
    }
};