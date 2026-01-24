class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>vec;
        string s1="Push";
        string s2="Pop";
        int k=0;
        int m=target.size();
        for(int i=0;i<n and k<m;i++){
            if((i+1)==target[k]){
                vec.push_back(s1);
                k++;
            }
            else{
                vec.push_back(s1);
                vec.push_back(s2);
            }
        }
        return vec;
    }
};