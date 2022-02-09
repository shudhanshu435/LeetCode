class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res=0,sum=0;
        for(int i=0;i<costs.size();i++){
            sum+=costs[i];
            if(sum<=coins)res++;
            if(sum>coins)break;
        }return res;
    }
};