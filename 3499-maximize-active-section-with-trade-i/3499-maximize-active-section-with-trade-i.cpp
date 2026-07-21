class Solution {
public: 
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int>v;
        int one=0,zero=0;
        for(char c:s){
            if(c=='1'){
                if(zero!=0)v.push_back(zero);
                zero=0;
                one++;
            }
            else{
                if(one!=0)v.push_back(one);
                one=0;
                zero++;
            }
        }
        v.push_back(zero+one);
        if(v.size()==1){
            if(s[0]=='0')return 0;return n;
        }
        if(v.size()==2){
            if(s[0]=='0')return v[1];
            return v[0];
        }
        if(v.size()==3){
            if(s[0]=='0')return v[0]+v[1]+v[2];
            return v[0]+v[2];
        }
        if(v.size()==4){
            return n;
        }
        if(v.size()==5){
            if(s[0]=='0')return max(n-v[0],n-v[v.size()-1]);
            return n;
        }
        vector<int>pref(n+1),suf(n+1);
        pref[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            pref[i]=(s[i]-'0')+pref[i-1];
        }
        suf[n-1]=s[n-1]-'0';
        for(int i=n-2;i>=0;i--){
            suf[i]=(s[i]-'0')+suf[i+1];
        }
        int st=0;
        int beg=1;
        int maxi=0;
        int ones = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') ones++;

        maxi = ones;

        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;

        if (s[0] == '0') {
            // v = 0,1,0,1,0,...
            for (int i = 1; i + 1 < v.size(); i += 2) {
                if (i - 1 >= 0 && i + 1 < v.size())
                    maxi = max(maxi, ones + v[i - 1] + v[i + 1]);
            }
        } else {
            // v = 1,0,1,0,1,...
            for (int i = 2; i + 1 < v.size(); i += 2) {
                maxi = max(maxi, ones + v[i - 1] + v[i + 1]);
            }
        }

        // for(auto i:v)cout<<i;
        // if(s[0]=='1' and s[n-1]=='0')return maxi-1;
        // if(s[n-1]=='1')return maxi-1;
        return maxi;
    }
};

// 00111011
// 1 11010101110 1