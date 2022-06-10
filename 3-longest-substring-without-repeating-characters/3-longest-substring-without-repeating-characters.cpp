class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>ss;
        
        int maxi=0;
        int st=0,en=0;
        while(st<s.size()){
            auto it = ss.find(s[st]);
            
            if(it==ss.end()){
                if(st-en+1>maxi)maxi=st-en+1;
                ss.insert(s[st]);
                st++;
            }
            else{
                ss.erase(s[en]);
                en++;
            }
        }
        return maxi;
    }
};