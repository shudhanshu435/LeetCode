class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string word;
        vector<string>vec,ans;
        while(ss>>word){
            vec.push_back(word);
        }
        for(int i=2;i<vec.size();i++){
            if(vec[i-2]==first and vec[i-1]==second)ans.push_back(vec[i]);
        }
        return ans;
        
    }
};