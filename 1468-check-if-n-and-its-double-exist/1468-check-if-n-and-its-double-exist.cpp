class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        int z=0;
        for(auto i:arr){
            mp[i]++;
            if(i%2==0 and (i/2)!=i and mp[i/2]!=0)return 1;
            if((i*2)!=i and mp[i*2]!=0)return 1;
            if(i==0)z++;
        }
        if(z>1)return 1;
        return 0;
    }
};