class Solution {
public:
    bool isCon(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')return false;
        return 1;
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char,int>mp;
        long long con=0,ans=0;
        int n=word.size();
        int start=0;
        vector<int>conind;

        for(int i=0;i<n;i++){
            if(isCon(word[i]))conind.push_back(i);
        }
        conind.push_back(n);

        // for(auto i:conind)cout<<i<<" ";
        // cout<<endl;

        for(int x=0;x<n;x++){
            mp[word[x]]++;
            int a=mp['a'],e=mp['e'],i=mp['i'],o=mp['o'],u=mp['u'];
            if(isCon(word[x]))con++;
            while(a and e and i and o and u){
                if(con>k){
                    if(isCon(word[start]))con--;
                    else mp[word[start]]--;
                }
                else if(con==k){
                    auto it=upper_bound(conind.begin(),conind.end(),x);
                    ans+=(*it-x);
                    if(isCon(word[start]))con--;
                    else mp[word[start]]--;
                }
                else
                    break;
                start++;
                a=mp['a'],e=mp['e'],i=mp['i'],o=mp['o'],u=mp['u'];
            }
        }
        return ans;
    }
};