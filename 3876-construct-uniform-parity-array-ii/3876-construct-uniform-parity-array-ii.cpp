class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int od=0,ev=0;
        int odd=INT_MAX;
        int even=INT_MAX;
        for(int i:nums1){
            if(i&1)od++;
            else ev++;
            if(i&1)odd=min(odd,i);
            else even=min(even,i);
        }
        // cout<<ev<<" "<<od<<endl;
        // cout<<even<<" "<<odd<<endl;
        if(ev==0 or od==0)return 1;
        if(even<odd)return 0;
        return 1;        
    }
};