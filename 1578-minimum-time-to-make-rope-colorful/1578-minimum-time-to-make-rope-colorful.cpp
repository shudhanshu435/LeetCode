// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int len=neededTime.size();
//         int sum=0;
//         for(int i=0;i<len-1;i++){
//             sum=neededTime[0];
//             maxi=neededTime[0];
//             if(colors[i]==colors[i+1])
//             {
//                 sum+=neededTime[i+1];
//                 maxi=max(maxi,neededTime[i+1])
//             }
//         }
//         return sum;
//     }
// };


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int len=neededTime.size();
        int sum=0;
        int maxi=neededTime[0];
        for(int i=0;i<len-1;i++){
            if(colors[i]==colors[i+1])
            {
                sum+=min(maxi,neededTime[i+1]);
                maxi=max(maxi,neededTime[i+1]);
            }
            else
            {
                maxi=neededTime[i+1];
                // cout<<maxi<<endl;
            }
                
        }
        return sum;
    }
};