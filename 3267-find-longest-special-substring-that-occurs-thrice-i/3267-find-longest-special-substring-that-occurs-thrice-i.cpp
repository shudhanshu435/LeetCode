class Solution {
public://aabbccccde
    int maximumLength(string s) {
        int n=s.length();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string curr="";
            for(int j=i;j<n;j++){
                if(curr.empty() or curr.back()==s[j]){
                    curr+=s[j];
                }
                else {
                    break;
                }
                mp[curr]++;
            }
        }
        int ans=-1;
        for(auto i:mp)cout<<i.first<<" "<<i.second<<endl;
        for(auto i:mp){
            string a=i.first;
            int freq=i.second;
            int len=a.length();
            if(freq>=3)ans=max(ans,len);
        }
        return ans;
    }
};