class Solution {
public:
    void backtrack(string &dig, int index, string c, vector<string>&ans, vector<string>&mp){
        if(index==dig.size()){
            ans.push_back(c);
            return;
        }

        string word=mp[dig[index]-'0'];
        for(char cc:word){
            c+=cc;
            backtrack(dig, index+1, c, ans, mp);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string c="";
        backtrack(digits, 0, c, ans, v);
        return ans;
    }
};