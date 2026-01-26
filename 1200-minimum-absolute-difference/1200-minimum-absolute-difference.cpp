class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=INT_MAX;
        int n=arr.size();
        for(int i=1;i<n;i++){
            diff=min(diff,arr[i]-arr[i-1]);
        }
        vector<vector<int>>v;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==diff){
                v.push_back({arr[i-1],arr[i]});
            }
        }
        return v;
    }
};