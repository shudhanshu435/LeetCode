class Solution {
public:
    string match(string &pattern){
        unordered_map<char,char>mp;
        string s="";
        int n=pattern.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(mp[pattern[i]]==0){
                mp[pattern[i]]=('a'+k);
                s+=('a'+k);
                k++;
            }
            else{
                s+=mp[pattern[i]];
            }
        }
        return s;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string s=match(pattern);
        // cout<<s<<endl;
        vector<string>ans;
        for(auto &i:words){
            if(match(i)==s)ans.push_back(i);
        }
        return ans;
    }
};