class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int n=s.length();
        int k=spaces.size();
        // for(int i=0;i<k;i++){
        //     spaces[i]+=i;
        // }
        int kk=0;
        for(int i=0;i<n;i++){
            if(kk<k and i==spaces[kk]){
                ans+=' ';
                kk++;
            }
            ans+=s[i];
        }
        return ans;
    }
};