class Solution {
public:
    vector<int> partitionLabels(string s) {
        // unordered_map<char,int>mp,mp2;
        vector<int>mp(26,0),mp2(26,0);
        for(auto i:s){
            mp[i-'a']++;
        }
        mp2=mp;
        int k=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']--;
            bool f=false;
            for(char c='a';c<='z';c++){
                if(mp2[c-'a']==0)continue;
                if(mp[c-'a']!=0 and mp[c-'a']!=mp2[c-'a']){
                    f=true;break;
                }
            }
            if(!f){
                ans.push_back(i+1-k);
                k=i+1;
            }

        }
        return ans;

    }
};