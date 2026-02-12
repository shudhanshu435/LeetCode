class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
                v[s[j]-'a']++;
                int val=-1;
                bool b=1;
                for(int k=0;k<26;k++){
                    if(v[k]!=0){
                        if(val!=-1){
                            if(val!=v[k])b=0;
                        }
                        else val=v[k];
                    }
                }
                if(b){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};