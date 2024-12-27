class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=INT_MIN;
        int n=values.size();
        vector<int>v,t;
        for(int i=0;i<n;i++){
            v.push_back(values[i]+i);
            t.push_back(values[i]-i);
        }
        for(int i=1;i<n;i++){
            v[i]=max(v[i],v[i-1]);
            t[n-1-i]=max(t[n-1-i],t[n-i]);
        }
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,v[i]+t[i+1]);
        }
        return maxi;
    }
};