class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int m=n/2;
        int x=capacityA,cnt=0;
        int y=capacityB;
        for(int i=0;i<n/2;i++)
        {
           if(plants[i]<=x)
                {
                    x-=plants[i];
                }
            else {
                cnt++;
                x=capacityA-plants[i];
            }
           if(plants[n-1-i]<=y)
           {
               y-=plants[n-1-i];
           }
            else {
                cnt++;
                y=capacityB-plants[n-1-i];
            }
        }
        int maxx=max(x,y);
        if(n&1){
            if(maxx<plants[n/2])cnt++;
        }
        
        return cnt;

    }
};