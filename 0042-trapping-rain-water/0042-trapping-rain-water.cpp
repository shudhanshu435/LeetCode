class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>ml(n,0),mr(n,0);
        ml[0]=height[0];
        for(int i=1;i<n;i++){
            ml[i]=max(ml[i-1],height[i]);
        }
        mr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            mr[i]=max(mr[i+1],height[i]);
        }

        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+=max(0,min(ml[i-1],mr[i+1])-height[i]);
        }
        return ans;
    }
};

// 0 1 0 2 1 0 1 3 2 1 2 1
