class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        cout<<m<<" "<<n<<endl;
        unordered_map<int,pair<int,int>>mm;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mm[mat[i][j]]={i,j};
            }
        }

        // for(auto v:mm){
        //     cout<<v.first<<" - ["<<v.second.first<<" , "<<v.second.second<<"]"<<endl;
        // }
        
        map<vector<int>,int>mp;
        int x,y;
        int ans=0;
        for(int i=0;i<m*n;i++){
            vector<int>v,t;
            v.push_back(-1);
            t.push_back(-2);
            x=mm[arr[i]].first;
            y=mm[arr[i]].second;
            cout<<x<<" "<<y<<endl;
            v.push_back(x);
            t.push_back(y);
            mp[v]++;
            mp[t]++;
            cout<<mp[v]<<" @@@ "<<mp[t]<<endl;
            if(mp[v]==n or mp[t]==m){
                ans=i;
                break;
            }
        }
        // for(auto m:mp){
        //     for(auto v:m.first)cout<<v<<" ";
        //     cout<<m.second<<endl;
        // }
        return ans;
    }
};