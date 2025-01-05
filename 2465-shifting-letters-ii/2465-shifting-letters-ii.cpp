class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>vec(n+1,0);
        for(auto i:shifts){
            int l=i[0];
            int r=i[1];
            if(i[2]==0){
                vec[l]-=1;
                vec[r+1]+=1;
            }
            else{
                vec[l]+=1;
                vec[r+1]-=1;
            }
        }
        for(int i=1;i<n;i++){
            vec[i]=vec[i-1]+vec[i];
        }
        string ans="";
        for(int i=0;i<n;i++){
            int ch=(int)s[i]-'a';
            ch+=vec[i];
            ch%=26;
            if(ch<0)ch=26+ch;
            cout<<ch<<" ";
            char c='a'+ch;
            ans+=c;
        }
        return ans;
    }
};