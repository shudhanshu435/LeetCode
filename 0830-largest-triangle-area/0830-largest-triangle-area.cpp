class Solution {
public:
    double area(int x1, int y1, int x2, int y2, int x3, int y3){
        return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0;
    }
    double largestTriangleArea(vector<vector<int>>& p) {
        int n=p.size();
        double maxi=0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    maxi=max(maxi,area(p[i][0],p[i][1],p[j][0],p[j][1],p[k][0],p[k][1]));
                }
            }
        }
        return maxi;
    }
};