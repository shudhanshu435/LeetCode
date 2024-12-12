class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>p;
        long long sum=0;
        for(auto i:gifts){
            p.push(i);
            sum+=i;
        }
        while(k--){
            auto i=p.top();
            int num=sqrt(i);
            p.pop();
            p.push(num);
            sum-=(i-num);
        }
        return sum;
    }
};

// 25 64 94 100
// 5 8 9 4 10
// 10, 8, 5, 3, 4