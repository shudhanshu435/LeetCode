class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>vec(n,0);
        unordered_map<string,pair<char,int>>mp;
        for(int i=0;i<n;i++){
            mp["id"+to_string(i)]={'O',0};
        }

        sort(events.begin(), events.end(),
            [](const vector<string>& a, const vector<string>& b) {
                int ta = stoi(a[1]);
                int tb = stoi(b[1]);
                if (ta != tb) return ta < tb;
                // same timestamp → OFFLINE before MESSAGE
                return a[0] == "OFFLINE" && b[0] == "MESSAGE";
            });

        for(auto &i:events){
            int t=stoi(i[1]);

            for(int k=0;k<n;k++){
                string key="id"+to_string(k);
                if(mp[key].first=='X' and mp[key].second<=t)mp[key]={'O',0};
            }
            if(i[0]=="MESSAGE") {
                if(i[2]=="HERE"){
                    for(int j=0;j<n;j++){
                        if(mp["id"+to_string(j)].first=='O')vec[j]++;
                    }
                }
                else if(i[2]=="ALL"){
                    for(auto &i:vec)i++;
                }
                else{
                    stringstream ss(i[2]);
                    string tt;
                    while(ss>>tt){
                        if(tt.rfind("id",0)==0){
                            int id=stoi(tt.substr(2));
                            if(id>=0 and id<n)vec[id]++;
                        }
                    }
                }
            }
            
            else{
                mp["id"+i[2]]={'X',t+60};
            }
        }
        return vec;
    }
};