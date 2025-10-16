class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int m) {
        unordered_map<int,int>mp;
        for(auto &i:nums){
            mp[((i%m)+m)%m]++;
        }
        // for(auto i:v)cout<<i<<" ";
        int i=0;
        while(1){
            if(mp[i]==0)return i;
            else if(mp[i]>1){
                mp[i+m]+=mp[i]-1;
            }
            i++;
        }
        return i;
    }
};


// -10, 1 6 7 8 13
// 0 1 1 2 3 3 4 5
// 0 1 2 3 4 5
