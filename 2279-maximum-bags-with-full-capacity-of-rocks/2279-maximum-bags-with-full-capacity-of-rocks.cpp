class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>vec;
        int cnt=0;
        for(int i=0;i<rocks.size();i++){
            int h=capacity[i]-rocks[i];
            if(h!=0)
            vec.push_back(h);
            else cnt++;
        }
        
        sort(vec.begin(),vec.end());
        int s=additionalRocks;
        for(int i=0;i<vec.size();i++){
            if(vec[i]<=s){
                s=s-vec[i];
                cnt++;
                if(s==0)break;
            }
        }cout<<cnt<<endl;
        return cnt;
    }
};