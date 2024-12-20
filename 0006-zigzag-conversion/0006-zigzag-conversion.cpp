class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        int k=1;
        int n=s.size();
        int m=n;
        vector<int>v;
        while(n>0){
            while(n>0 and k<=numRows){
                v.push_back(k);
                k++;
                n--;
            }
            k=k-2;
            while(n>0 and k>=1){
                v.push_back(k);
                k--;
                n--;
            }
            k=k+2;
        }
        n=m;
        // for(auto i:v)cout<<i<<" ";
        map<int,vector<char>>mp;
        for(int i=0;i<n;i++){
            mp[v[i]].push_back(s[i]);
        }
        string ans="";
        for(auto i:mp){
            for(auto j:i.second)ans+=j;
        }

        return ans;
    }
};