class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp,mp2;
        for(auto i:s){
            mp[i]++;
        }
        mp2=mp;
        int k=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            mp[s[i]]--;
            bool f=false;
            for(char c='a';c<='z';c++){
                if(mp2[c]==0)continue;
                if(mp[c]!=0 and mp[c]!=mp2[c]){
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