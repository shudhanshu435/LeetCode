using intt = long long; 
class Solution {
public:
    string fractionToDecimal(intt num, intt den) {
        unordered_map<intt,int>mp;
        if(num==0)return "0";
        bool neg=0;
        if(num<0 and den<0)neg=0;
        else if(num<0 or den<0)neg=1;
        num=llabs(num);
        den=llabs(den);

        string ans="";
        bool b=1;
        
        while(1){
            intt q=num/den;
            intt r=num%den;
            ans+=to_string(q);
            if(r==0){
                if(neg){
                    ans.insert(ans.begin(),'-');
                }
                return ans;
            }
            else if(b){
                ans+='.';
                b=0;
            }
            if(mp.count(r)){
                ans.insert(mp[r],"(");
                ans+=")";
                break;
            }
            mp[r]=ans.size();
            r*=10;
            while(r<den){
                r*=10;
                ans+='0';
            }
            num=r;
        }

        if(neg){
            ans.insert(ans.begin(),'-');
        }
        return ans;
        
    }
};