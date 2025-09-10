class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lan, vector<vector<int>>& frnd) {
        unordered_map<int,int>mp;
        unordered_set<int>ss;
        for(auto v:frnd){
            int a=v[0],b=v[1];
            unordered_set<int>s;
            for(auto &i:lan[a-1]){
                s.insert(i);
            }
            for(auto &i:lan[b-1]){
                s.insert(i);
            }
            // for(auto v:s){
            //     cout<<v<<" ";
            // }
            int len=lan[a-1].size()+lan[b-1].size();
            if(s.size()==len){
                ss.insert(a);
                ss.insert(b);
            }
        }
         if (ss.empty()) return 0;

        int ans = INT_MAX;
        for (int lang = 1; lang <= n; ++lang) {
            int already = 0;
            for (int user : ss) {
                for (int l : lan[user - 1]) {
                    if (l == lang) {
                        already++;
                        break;
                    }
                }
            }
            ans = min(ans, (int)ss.size() - already);
        }

        
        return ans;
    }
};