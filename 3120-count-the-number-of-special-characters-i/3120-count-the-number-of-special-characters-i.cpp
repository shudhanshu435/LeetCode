class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>v(60,0);
        for(auto &ch:word){
            v[ch-'A']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(v[i]>0 and v[i+32]>0)ans++;
        }
        return ans;
    }
};