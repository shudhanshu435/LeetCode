class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start==destination)return 0;
        int sum=0,res=0;
        for(int i=0;i<distance.size();i++){
            sum+=distance[i];
        }
        // cout<<sum;
        if(start>destination){
            swap(start,destination);
        }
        for(int i=start;i<destination;i++){
                res+=distance[i];
        }
        if(res<sum-res)return res;
        else return sum-res;
        
    }
};