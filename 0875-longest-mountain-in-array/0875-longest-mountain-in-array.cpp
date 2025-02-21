class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0,n=arr.size();
        for(int i=1;i<n-1;i++){
            bool f=0,ff=0;
            int left=i;
            while(left-1>=0 and arr[left]>arr[left-1]){
                left--;
                f=1;
            }
            int right=i;
            while(right+1<n and arr[right]>arr[right+1]){
                right++;
                ff=1;
            }
            if(f and ff)
            ans=max(ans,right-left+1);
            // cout<<left<<"  "<<right<<" ";
            // cout<<ans<<endl;
        }
        if(ans>=3)return ans;
        return 0;
        // return ans;
    }
};

/*

2 1 4 7 3 2 5
2 1 1 1 1 1 1
1 1 2 2 2 2 5

*/