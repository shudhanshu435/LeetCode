class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int cnt=0;
        int m=strs[0].size();
        for(int i=0;i<m;i++){
            bool b=1;
            for(int j=0;j<n-1;j++){
                if(strs[j][i]>strs[j+1][i]){
                    b=0;break;
                }
            }
            if(!b)cnt++;
        }
        return cnt;
    }
};