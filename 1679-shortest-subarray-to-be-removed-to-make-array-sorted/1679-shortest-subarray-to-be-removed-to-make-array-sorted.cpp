class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int i=1,j=n-2;
        vector<int>s;
        while(i<n and arr[i]>=arr[i-1])i++;
        i--;
        // cout<<i<<endl;
        s.push_back(arr[n-1]);
        while(j>=0){
            if(arr[j]<=arr[j+1]){
                s.push_back(arr[j]);
                j--;
            }
            else break;
        }
        int m=s.size();
        int ans=n-m;
        reverse(s.begin(),s.end());
        // for(auto i:s)cout<<i<<" ";
        // cout<<endl;
        while(i>=0){
            int ind=lower_bound(s.begin(),s.end(),arr[i])-s.begin();
            // cout<<ind<<endl;
            ans=min(ans,n-m+ind-i-1);
            i--;
        }
        return max(ans,0);
    }
};