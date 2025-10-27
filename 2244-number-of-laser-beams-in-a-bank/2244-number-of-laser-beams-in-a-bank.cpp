class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int laser1=-1,laser2=0,ans=0;
        for(auto &i:bank){
            laser2=0;
            for(auto &v:i){
                if(v=='1')laser2++;
            }
            if(!laser2)continue;
            if(laser1!=-1)ans+=laser2*laser1;
            laser1=laser2;
        }
        return ans;
    }
};