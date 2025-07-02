class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string,bool>mp;
        vector<string>ans;
        string c="";
        for(auto i:s){
            c+=i;
            if(mp[c]){
                continue;
            }
            ans.push_back(c);
            mp[c]=1;
            c="";
        }
        return ans;
        
    }
};