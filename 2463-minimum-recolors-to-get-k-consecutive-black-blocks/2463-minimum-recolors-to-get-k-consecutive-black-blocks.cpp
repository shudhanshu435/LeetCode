class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wblu=0;
        int n=blocks.size();
        vector<int>v;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')wblu++;
        }
        v.push_back(wblu);
        for(int i=0;i<n-k;i++){
            if(blocks[i]=='W')wblu--;
            if(blocks[i+k]=='W')wblu++;
            v.push_back(wblu);
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};