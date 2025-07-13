class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0,j=0;
        int p=players.size();
        int t=trainers.size();
        while(i<p and j<t){
            if(players[i]<=trainers[j]){
                i++;j++;
            }
            else j++;
        }
        return min(i,j);
    }
};