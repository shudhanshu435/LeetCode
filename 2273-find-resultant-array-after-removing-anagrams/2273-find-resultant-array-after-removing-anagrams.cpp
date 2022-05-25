class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        //sort(words.begin(),words.end());
        vector<string>vec;
        vec.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string s=words[i];
            sort(words[i].begin(),words[i].end());
            sort(words[i-1].begin(),words[i-1].end());
            if(words[i]!=words[i-1]){
            vec.push_back(s);
                }
        }
        return vec;
    }
};