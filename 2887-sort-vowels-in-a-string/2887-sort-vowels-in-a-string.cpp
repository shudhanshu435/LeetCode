class Solution {
public:
    bool isv(char c){
        if(c=='A' or c=='E' or c=='I' or c=='O' or c=='U' or c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;
        return 0;
    }
    string sortVowels(string s) {
        multiset<char>st;
        for(auto i:s){
            if(isv(i))st.insert(i);
        }
        for(auto &i:s){
            if(isv(i)){
                i=*st.begin();
                st.erase(st.begin());
            }
        }
        return s;
    }
};