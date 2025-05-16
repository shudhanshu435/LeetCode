class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s=sqrt(area);
        for(;s<=area;s++)if(area%s==0)return {max(s,area/s), min(s,area/s)};
        return {};
    }
};

/*

40
1 2 4 5 8 10 20 40

*/