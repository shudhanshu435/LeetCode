class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            char ch=order[i];
            if(mp[ch]!=0){
                while(mp[ch]){
                    ans+=ch;
                    mp[ch]--;
                }
                mp.erase(ch);
            }
        }
        for(auto i:s){
            if(mp[i]!=0)ans+=i;
        }
        return ans;
    }
};

/* 

c - b - a
a - b - c - d


*/