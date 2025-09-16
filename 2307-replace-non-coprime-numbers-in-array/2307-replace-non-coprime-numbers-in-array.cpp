class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long>s;
        for(auto i:nums){
            if(s.empty())s.push(i);
            else{
                long long one=i;
                while(!s.empty()){
                    long long top_=s.top();
                    int g=__gcd(one,top_);
                    if(g!=1){
                        s.pop();
                        one=(one*1ll*top_)/g;
                    }
                    else {
                        break;
                    }
                }
                s.push(one);
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