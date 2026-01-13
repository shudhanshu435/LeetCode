class Solution {
public:
    bool pos(double mid, vector<vector<int>>& sq){
        double larea=0,uarea=0;
        int n=sq.size();
        for(int i=0;i<n;i++){

            double y=sq[i][1];
            double side=sq[i][2];
            double top=y+side;

            if(top<=mid){
                larea+=side*side;
            }
            else if(y>=mid){
                uarea+=side*side;
            }
            else{
                larea+=(mid-y)*side;
                uarea+=(top-mid)*side;
            }
        }
        return uarea>larea;
    }
    double separateSquares(vector<vector<int>>& sq) {
        double right=0;
        for(auto i:sq){
            right=max(right,(double)i[1]+i[2]);
        }
        double l=0,r=(double)right;
        double ans=0;
        for(int i=0;i<=80;i++){
            double mid=l+(r-l)/2;
            if(pos(mid,sq)){
                ans=mid;
                l=mid;
            }
            else{
                r=mid;
            }
        }
        return ans;

    }
};