class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>vec;
        vec.push_back(0);
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            vec.push_back(sum);
        }
        sort(vec.begin(),vec.end());
        return vec[vec.size()-1];
    }
};