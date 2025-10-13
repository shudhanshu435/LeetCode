class Solution {
public:
    int n,K;
    int solve(vector<int>&energy, int i, vector<int>&t){
        if(i>=n)return 0;

        if(t[i]!=INT_MIN)return t[i];
        return t[i]=energy[i]+solve(energy,i+K,t);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        n=energy.size();
        K=k;
        vector<int>t(n,INT_MIN);

        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,solve(energy,i,t));
        }
        return maxi;
        
    }
};