class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>w;
        int n=words.size();
        for(int i=0;i<n;i++){
            w.push_back(words[i]);
            sort(words[i].begin(),words[i].end());
            if(i>0){
                if(words[i]==words[i-1])w.pop_back();
            }
        }
        return w;
    }
};