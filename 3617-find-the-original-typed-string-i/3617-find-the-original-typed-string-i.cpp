class Solution {
public:
    int possibleStringCount(string word) {
        int l=1,ans=0;
        int n=word.size();
        for(int i=0;i<n-1;i++){
            if(word[i]==word[i+1])l++;
            else{
                ans+=l-1;
                l=1;
            }
        }
        return ans+l;
        

    }
};