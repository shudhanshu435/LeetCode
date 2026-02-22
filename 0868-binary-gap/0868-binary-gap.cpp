class Solution {
public:
    int binaryGap(int n) {
        int f=-1,ans=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i) and f==-1){
                f=i;
            }
            else if(n&(1<<i)){
                ans=max(ans,i-f);
                f=i;
            }
        }
        return ans;
    }
};