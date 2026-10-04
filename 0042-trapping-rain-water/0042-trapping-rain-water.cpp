class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int ans=0;
        int lm=0,rm=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(lm<=height[l])lm=height[l];
                else ans+=lm-height[l];
                l++;
            }
            else{
                if(rm<=height[r])rm=height[r];
                else ans+=rm-height[r];
                r--;
            }
        }
        return ans;
    }
};

// 0 1 0 2 1 0 1 3 2 1 2 1
