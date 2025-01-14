class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp1,mp2;
        int maxi=0;
        vector<int>vec;
        int k=0;
        for(int i=0;i<A.size();i++){
            k+=2;
            mp1[A[i]]++;
            mp1[B[i]]++;
            vec.push_back(k-mp1.size());
        }
        return vec;

    }
};