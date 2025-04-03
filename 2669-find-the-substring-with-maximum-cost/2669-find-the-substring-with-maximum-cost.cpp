class Solution {
public:
    int maxSum(vector<int>&v){
        int curr=0,maxi=0;
        for(auto i:v){
            curr+=i;
            if(curr<0)curr=0;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int sz=s.size();
        vector<int>v(sz);
        unordered_map<char,int>mp;
        for(int i=0;i<chars.size();i++)mp[chars[i]]=vals[i];
        for(int i=0;i<sz;i++){
            if(mp.count(s[i]))v[i]=mp[s[i]];
            else v[i]=(s[i]-'a')+1;
        }
        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;
        return maxSum(v);

        // return 0;
    }
};