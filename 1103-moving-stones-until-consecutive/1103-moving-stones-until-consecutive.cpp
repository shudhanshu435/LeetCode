class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x=min({a,b,c});
        int z=max({a,b,c});
        int y=(a+b+c)-(x+z);
        int maxi=z-y-1+y-x-1; //z-x-2
        int mini;
        if(z-y>=3 and y-x>=3)mini=2;
        else if(z-y==1 and y-x==1)mini=0;
        else mini=1;
        return {mini,maxi};
    }
};