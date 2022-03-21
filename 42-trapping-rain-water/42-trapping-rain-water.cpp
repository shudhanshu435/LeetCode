class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int a[n];
        a[0]=height[0];
        for(int i=1;i<n;i++)a[i]=max(a[i-1],height[i]);
        int r[n];
        r[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)r[i]=max(r[i+1],height[i]);
        for(int i=0;i<n;i++)ans+=min(a[i],r[i])-height[i];
        
        return ans;
    }
};