class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=0,sum=0;
        int i=piles.size()-2;
        while(n<piles.size()/3){
            sum+=piles[i];
            i=i-2;
            n++;
        }return sum;
    }
};