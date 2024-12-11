class Solution {
public:
    int maximumLength(string s) {
        // int n=s.length();
        // unordered_map<string,int>mp;
        
        // for(int i=0;i<n;i++){
        //     string curr="";
        //     for(int j=i;j<n;j++){
        //         if(curr.empty() or curr.back()==s[j]){
        //             curr+=s[j];
        //         }
        //         else {
        //             break;
        //         }
        //         mp[curr]++;
        //     }
        // }
        // int ans=-1;
        // for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;
        // for(auto i:mp){
        //     string a=i.first;
        //     int freq=i.second;
        //     int len=a.length();
        //     if(freq>=3)ans=max(ans,len);
        // }
        // return ans;

//   aaaabb

        int n=s.length();
        map<pair<int,int>,int>mp;
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    cnt++;
                }
                else {
                    break;
                }
                mp[make_pair(s[i],cnt)]++; 
            }
        }
        int ans=-1;
        for(auto i:mp){
            int freq=i.second;
            if(freq>=3)ans=max(ans,i.first.second);
        }
        return ans;
    }
};