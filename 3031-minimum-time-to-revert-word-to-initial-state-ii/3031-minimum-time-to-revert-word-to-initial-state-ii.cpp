class Solution {
public:
    vector<int> lps(string word){
        int len=0;
        int i=1;
        int n=word.size();
        vector<int>v(n,0);
        while(i<n){
            if(word[len]==word[i]){
                len++;
                v[i]=len;
                i++;
            }
            else{
                if(len==0)i++;
                else len=v[len-1];
            }
        }
        
        return v;
    }

    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        vector<int>v=lps(word);
        int curr=v[n-1];
        while (curr > 0) {
            if ((n - curr) % k == 0) {
                return (n - curr) / k;
            }
            curr = v[curr - 1];
        }
        return (n + k - 1) / k;
    }
};