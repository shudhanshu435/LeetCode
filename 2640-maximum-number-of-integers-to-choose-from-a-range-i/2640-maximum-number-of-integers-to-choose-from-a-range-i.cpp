class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>s;
        for(auto i:banned)s.insert(i);
        long long sum=0;
        int cnt=0;
        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;
        for(int i=1;i<=n;i++){
            if(s.count(i))continue;
            else{
                sum+=i;
                if(sum>maxSum)break;
                cnt++;
            }
        }
        return cnt;
    }
};