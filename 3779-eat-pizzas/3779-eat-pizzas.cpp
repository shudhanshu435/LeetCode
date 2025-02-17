class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int day=pizzas.size()/4;
        int od=ceil(day/2.0);
        int ev=day-od;
        int i=pizzas.size()-1;
        long long ans=0;
        while(od--){
            ans+=pizzas[i--];
        }
        i--;
        while(ev--){
            ans+=pizzas[i];
            i-=2;
        }
        return ans;
    }
};