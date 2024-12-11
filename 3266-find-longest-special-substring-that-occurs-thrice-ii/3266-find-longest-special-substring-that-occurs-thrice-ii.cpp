class Solution {
public: // aaaabbc
    int maximumLength(string s) {
        int n=s.length();
        vector<vector<int>>vec(26, vector<int>(n+1,0));
        int currchar=s[0];
        int length=0;
        for(int i=0;i<n;i++){
            if(s[i]==currchar){
                length+=1;
                vec[s[i]-'a'][length]+=1;
            }
            else{
                length=1;
                vec[s[i]-'a'][length]+=1;
                currchar=s[i];
            }
        }
        int ans=-1;
        for(int i=0;i<26;i++){
            int rightsum=0;
            for(int j=n;j>=1;j--){
                rightsum+=vec[i][j];
                if(rightsum>=3){
                    ans=max(ans,j);
                    break;
                }
            }
        }
        return ans;
    }
};