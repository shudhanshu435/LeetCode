class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i:asteroids){
            if(m<i)return 0;
            m+=i;
        }
        return 1;
    }
};