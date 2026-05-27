class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        int ans=0;
        for(char c='a';c<='z';c++){
            int s=-1;
            char cc=c-32;
            int l=INT_MAX;
            // cout<<c<<" "<<cc<<endl;
            for(int i=0;i<n;i++){
                if(word[i]==c){
                    s=i;
                }
                else if(word[i]==cc){
                    l=min(i,l);
                }
            }
            // cout<<s<<" "<<l<<endl;
            if(s!=-1 and l!=INT_MAX and s<l)ans++;
        }
        return ans;
    }
};