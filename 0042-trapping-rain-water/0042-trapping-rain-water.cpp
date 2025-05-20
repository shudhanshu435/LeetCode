class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>p(n),s(n);
        p[0]=h[0];
        for(int i=1;i<n;i++){
            p[i]=max(h[i],p[i-1]);
        }
        s[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=max(h[i],s[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(p[i],s[i])-h[i];
        }
        return ans;
    }
};


/*


0 1 0 2 1 0 1 3 2 1 2 1
0 1 1 2 2 2 2 3 3 3 3 3
3 3 3 3 3 3 3 3 2 2 2 1

*/