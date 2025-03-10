class Solution {
public:
    bool isCon(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')return false;
        return 1;
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char,int>mp;
        int con=0,ans=0;
        int n=word.size();
        int start=0;
        for(int x=0;x<n;x++){
            mp[word[x]]++;
            int a=mp['a'],e=mp['e'],i=mp['i'],o=mp['o'],u=mp['u'];
            if(isCon(word[x]))con++;
            vector<pair<char,int>>v;
            while(a and e and i and o and u){
                if(con>k){
                    if(isCon(word[start]))con--;
                    else mp[word[start]]--;
                }
                else if(con==k){
                    ans++;
                    if(isCon(word[start]))break;
                    else {
                        v.push_back({word[start],start});
                        mp[word[start]]--;
                    }
                }
                else
                    break;
                start++;
                a=mp['a'],e=mp['e'],i=mp['i'],o=mp['o'],u=mp['u'];
            }
            if(!v.empty())start=v[0].second;
            for(auto i:v)mp[i.first]++;
            v.clear();
        }
        return ans;
    }
};