class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        for(auto &i:stones)i=i%3;
        int n=stones.size();
        int one=0,z=0,tw=0;
        for(auto i:stones){
            if(i==0)z++;
            else if(i==1)one++;
            else tw++;
        }
        if(one==0 and tw==0)return 0;
        if(z%2==0){
            return one>=1 && tw>=1;
        }
        
        return abs(one-tw)>2;
    }
};


// 1 1 2
// 2 0 1