class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp,m;
        for(auto i:words2){
            for(auto k:i){
                m[k]++;
            }
            for(auto j:m){
                char c=j.first;
                mp[c]=max(m[c],mp[c]);
            }
            m.clear();
        }
        // for(auto i:mp)
        //     cout<<i.first<<" "<<i.second<<endl;

        // mp.clear();
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<"asdfg"<<endl;
        vector<string>v;
        for(auto i:words1){
            bool univ=true;
            for(auto j:i){
                m[j]++;
            }
            
            if(mp.size()<=m.size()){
                for(auto k:mp){
                    char c=k.first;
                    if(mp[c]>m[c]){
                        univ=false;
                        break;
                    }
                }
                if(univ)v.push_back(i);
            }

            m.clear();
        }
        return v;
    }
};