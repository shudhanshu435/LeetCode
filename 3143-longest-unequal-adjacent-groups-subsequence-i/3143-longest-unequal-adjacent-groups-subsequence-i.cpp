class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>v;
        v.push_back(words[0]);
        int bef=groups[0];
        for(int i=1;i<groups.size();i++){
            if(groups[i]!=bef){
                v.push_back(words[i]);
                bef^=1;
            }
        }
        return v;
    }
};