class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char c=letters[0];
        for(char cc:letters){
            if(cc>target){
                return cc;
            }
        }
        return c;
    }
};