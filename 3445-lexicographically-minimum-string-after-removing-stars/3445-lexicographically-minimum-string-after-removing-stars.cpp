class Solution {
public:
    string clearStars(string s) {
        unordered_map<char,vector<int>>mp;
        int n=s.length();
        vector<int>vec(n);
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                // cout<<i<<endl;
                vec[i]=-1;
                for(char j='a';j<='z';j++){
                    if(mp[j].empty())continue;
                    else{
                        int ind=mp[j].back();
                        mp[j].pop_back();
                        vec[ind]=-1;
                        break;
                    }
                }
            }
            else mp[s[i]].push_back(i);
        }
        // for(auto i:vec)cout<<i<<" ";
        // cout<<endl;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(vec[i]!=-1)ans+=s[i];
        }

        return ans;
    }
};

//aabaagaa*