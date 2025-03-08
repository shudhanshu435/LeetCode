class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,w=0;
        for(;i<k;i++){
            if(blocks[i]=='W')w++;
        }
        int ans=w;
        int kk=0;
        for(;i<blocks.size();i++){
            if(blocks[i]=='W')w++;
            if(blocks[kk++]=='W')w--;
            ans=min(ans,w);
        }

        return ans;

    }
};