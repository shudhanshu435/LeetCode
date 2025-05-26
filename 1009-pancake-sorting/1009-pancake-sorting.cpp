class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int>v;
        for(int i=n;i>0;i--){
            for(int j=0;j<n;j++){
                if(arr[j]==i and j!=0){
                    reverse(arr.begin(),arr.begin()+(j+1));
                    v.push_back(j+1);
                    // for(auto ii:arr)cout<<ii<<" ";
                    // cout<<endl;
                }
            }
            reverse(arr.begin(),arr.begin()+i);
            v.push_back(i);
            // for(auto ii:arr)cout<<ii<<" ";
            // cout<<endl;
        }
        return v;
    }
};