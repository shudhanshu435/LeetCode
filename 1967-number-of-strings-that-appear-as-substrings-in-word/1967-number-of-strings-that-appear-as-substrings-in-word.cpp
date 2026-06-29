class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,bool>mp;
        int n=word.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mp[word.substr(i,j-i+1)]=1;
            }
        }
        int ans=0;
        for(auto &i:patterns)ans+=mp[i];
        return ans;
    }
};