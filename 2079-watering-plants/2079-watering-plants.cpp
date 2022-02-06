class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=capacity,cnt=0;
        for(int i=0;i<plants.size();i++){
            if(plants[i]<=n){
                cnt+=1;
                n=n-plants[i];
            }
            else{
                cnt+=i+i+1;
                n=capacity-plants[i];
            }
        }
        return cnt;
    }
};