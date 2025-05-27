class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tot=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0)tot+=i;
            else tot-=i;
        }
        return tot;
    }
};