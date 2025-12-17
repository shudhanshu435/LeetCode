class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 1;
        int maxi=1;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                if(arr[i]>arr[i+1])cnt++;
                else {
                    maxi=max(maxi,cnt);
                    cnt=1;
                }
            }
            else{
                if(arr[i]<arr[i+1])cnt++;
                else {
                    maxi=max(maxi,cnt);
                    cnt=1;
                }
            }
        }
        maxi=max(maxi,cnt);
        cnt=1;
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                if(arr[i]<arr[i+1])cnt++;
                else {
                    maxi=max(maxi,cnt);
                    cnt=1;
                }
            }
            else{
                if(arr[i]>arr[i+1])cnt++;
                else {
                    maxi=max(maxi,cnt);
                    cnt=1;
                }
            }
        }
        maxi=max(maxi,cnt);
        // cout<<maxi<<endl;
        return maxi;
    }
};