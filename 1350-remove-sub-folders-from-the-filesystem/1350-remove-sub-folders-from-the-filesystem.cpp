class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>vec;
        unordered_map<string,bool>mp;
        for(auto i:folder){
            int sl=0;
            bool yes=0;
            string s="";
            for(char c:i){
                s+=c;
                if(c=='/')sl++;
                if(c=='/' and sl>=2){
                    s.pop_back();
                    if(mp[s]){
                        yes=1;
                        break;
                    }
                    s+='/';
                }
            }
            if(!yes){
                mp[s]=1;
                vec.push_back(s);
            }
        }
        return vec;
    }
};