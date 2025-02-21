class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>v;
        map<vector<int>,bool>mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int j=i+1;
            int sum=-arr[i];
            int k=arr.size()-1;
            while(j<k){
                if(arr[j]+arr[k]==sum){
                    if(mp[{arr[i],arr[j],arr[k]}]==0)v.push_back({arr[i],arr[j],arr[k]});
                    mp[{arr[i],arr[j],arr[k]}]=1;
                    j++;k--;
                }
                else if(arr[j]+arr[k]<sum)j++;
                else k--;
            }
        }
        return v;
    }
};