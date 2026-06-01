class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int size=cost.size();
        int sum=0,sum1=0;
        if(size==1)return cost[0];
        if(size==2)return cost[0]+cost[1];
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        for(int i=0;i<size;i++){
           sum+=cost[i];
        }
        int i=2;
        while(i<size){
            sum1+=cost[i];
            i=i+3;
        }
        return sum-sum1;
    }
};