class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vec;
        for(int i=0;i<arr.size();i++){
            vec.push_back(make_pair(__builtin_popcount(arr[i]),arr[i]) );
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=0;i<vec.size();i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};