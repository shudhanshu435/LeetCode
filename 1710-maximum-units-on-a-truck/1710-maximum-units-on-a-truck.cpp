class Solution {
public:
    static bool sortcol( const vector<int>& v1,const vector<int>& v2 ) {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),sortcol);
        int sum=0;
        if(boxTypes[0][0]>=truckSize)return truckSize*boxTypes[0][1];
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
               sum+=boxTypes[i][0]*boxTypes[i][1];
               truckSize-=boxTypes[i][0];
            }
            else{
                sum+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return sum;
    }
};