class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>ss;
        for(auto i:s){
            if(i==')'){
                if(!ss.empty() and ss.top()=='('){
                    ss.pop();
                }
                else ss.push(i);
            }
            else ss.push(i);
        }
        
        return ss.size();
    }
};

// )))((())