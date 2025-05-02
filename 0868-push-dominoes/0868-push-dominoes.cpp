class Solution {
public:
    string pushDominoes(string d) {
        string ans="";
        int n=d.size();
        string res(n,'.');
        vector<int>v;
        for(int i=0;i<d.size();i++){
            if(d[i]!='.'){
                ans+=d[i];
                v.push_back(i);
            }
        }
        if(v.empty())return d;
        int f=v[0];
        if(ans[0]=='L'){
            for(int i=0;i<=f;i++){
                res[i]='L';
            }
        }
        int s=v[v.size()-1];
        if(ans[v.size()-1]=='R'){
            for(int i=s;i<n;i++){
                res[i]='R';
            }
        }
        for(int i=0;i<v.size()-1;i++){
            if(ans[i]=='L' and ans[i+1]=='R')continue;
            if(ans[i]=='R' and ans[i+1]=='L'){
                int dif=v[i+1]-v[i]-1;
                dif/=2;
                for(int j=v[i];j<=v[i]+dif;j++){
                    res[j]='R';
                }
                for(int j=v[i+1];j>=v[i+1]-dif;j--){
                    res[j]='L';
                }
            }
            else if(ans[i]==ans[i+1]){
                for(int j=v[i];j<=v[i+1];j++){
                    res[j]=ans[i];
                }
            }
        }
        return res;
    }
};

/*

". L . R . . . L R . .  L  .  .  .  L "
"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"



*/