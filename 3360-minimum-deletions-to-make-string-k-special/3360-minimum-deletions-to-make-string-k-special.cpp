class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> frq(26,0);
        int n=word.size(),i,j=0,ans=INT_MAX;
        for(i=0;i<n;i++) frq[word[i]-'a']++;
        frq.erase(remove(frq.begin(),frq.end(),0),frq.end());
        if(frq.size()==0) return j;
        sort(frq.begin(),frq.end(),greater<int>());
        for(i=0;i<frq.size();i++){
            int d=0;
            for(j=0;j<frq.size();j++){
                if(frq[j]>frq[i]+k) d+=frq[j]-(frq[i]+k);
                else if(frq[j]<frq[i]) d+=frq[j];
            }
            ans=min(ans,d);
        }
        return ans;
    }
};