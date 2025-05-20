class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int i=0,j=p.size()-1;
        sort(p.begin(),p.end());
        int ans=0;
        while(i<=j){
            if(p[i]+p[j]>limit){
                j--;
            }
            else if(p[i]+p[j]<=limit){
                i++;j--;
            }
            ans++;
        }

        return ans;
    }
};