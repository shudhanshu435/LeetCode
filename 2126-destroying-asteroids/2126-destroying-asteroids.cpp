class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        long long tot=mass;
        for(int i=0;i<n;i++){
            if(tot<a[i])return 0;
            tot+=a[i];
        }
        return 1;
    }
};