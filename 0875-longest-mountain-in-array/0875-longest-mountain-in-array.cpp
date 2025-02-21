class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0,n=arr.size();
        int cnt=1;
        bool f=0,ff=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                cnt++;
                f=1;
            }
            else if(arr[i]>arr[i+1]){
                cnt++;
                ff=1;
                if(f)ans=max(ans,cnt);
                if(i+2<n and arr[i+1]<arr[i+2]){
                    cnt=1;
                }
            }
            else {
                cnt=1;f=0;ff=0;
            }
            // if(f and ff)
            // ans=max(ans,cnt);
            // if(i+2<n and arr[i+1]<arr[i] and arr[i+1]<arr[i+2]){
            //     cnt=1;
            //     ff=0;
            // }

            // ans=max(ans,right-left+1);
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