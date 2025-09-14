class Solution {
public:
    bool isVowel(char ch) {
        ch=toupper(ch); 
        return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    vector<string> spellchecker(vector<string>& ww, vector<string>& queries) {
        unordered_map<string, vector<int>>mp;
        unordered_map<string,bool>mp2;
        for(int i=0;i<ww.size();i++){
            mp2[ww[i]]=1;
            string s=ww[i];
            transform(s.begin(),s.end(),s.begin(),::tolower);
            // cout<<s<<endl;
            mp[s].push_back(i);
            string t="";
            for(auto u:ww[i]){
                if(isVowel(u)){
                    t+='A';
                }
                else t+=toupper(u);
            }
            mp[t].push_back(i);
        }

        vector<string>ans;

        for(auto &i:queries){
            if(mp2[i]){
                ans.push_back(i);
                // cout<<"s\n";
            }
            else{
                string s=i;
                transform(s.begin(),s.end(),s.begin(),::tolower);
                if(mp.count(s))ans.push_back(ww[mp[s][0]]);
                else{
                    string t="";
                    for(auto u:i){
                        if(isVowel(u)){
                            t+='A';
                        }
                        else t+=toupper(u);
                    }
                    if(mp.count(t))ans.push_back(ww[mp[t][0]]);
                    else ans.push_back("");
                }
            }
        }
        return ans;
    }
};