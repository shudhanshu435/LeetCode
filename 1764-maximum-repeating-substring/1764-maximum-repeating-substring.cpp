class Solution {
public:
    int maxRepeating(string sequence, string word) {
        vector<int>ind;
        int n=sequence.size();
        int w=word.size();
        int maxi=0;
        for(int i=0;i<=n-w;i++){
            int cnt=0;
            for(int j=i;j<n;j+=w){
                if(sequence.substr(j,w)==word)cnt++;
                else break;
            }
            maxi=max(maxi,cnt);

        }
        return maxi;
        
    }
};