class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp1,mp2;
        int maxi=0;
        vector<int>vec;
        for(int i=0;i<A.size();i++){
            mp1[A[i]]++;
            mp2[B[i]]++;
            maxi=max(maxi,max(A[i],B[i]));
            int cnt=0;
            for(int j=1;j<=maxi;j++){
                if(mp1[j]!=0 and mp2[j]!=0 and mp1[j]==mp2[j])cnt++;
            }
            vec.push_back(cnt);
        }
        return vec;

    }
};