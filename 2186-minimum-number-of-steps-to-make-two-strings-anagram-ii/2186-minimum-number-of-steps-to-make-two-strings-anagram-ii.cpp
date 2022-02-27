class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char ,int>m;
        
        for(auto c:s)m[c]++;
        for(auto c:t)m[c]--;
        
        int ans=0;
        for(auto it: m)
            ans+=abs(it.second);
        
        return ans;
    }
};