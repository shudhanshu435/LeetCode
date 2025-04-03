class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.length();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        int cnt=0;
        for(auto w:words){
            bool bb= true;
            int k=0;
            for(auto c:w){
                // for(auto i:mp[c])cout<<i<<" ";
                // cout<<endl;
                // cout<<endl;
                // cout<<k<<endl;
                auto it=lower_bound(mp[c].begin(),mp[c].end(),k);
                if(it==mp[c].end()){
                    bb=false;
                    break;
                }
                else k=*it+1;
            }
            // cout<<w<<" ";
            if(bb)cnt++; 
        }
        // cout<<"feda";
        return cnt;
    }
};