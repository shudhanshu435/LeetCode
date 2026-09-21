class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();

        vector<long long>res,x,y;
        for(int i=0;i<k;++i){
            res.push_back(0);
            x.push_back(0);
            y.push_back(0);
        }

        for(int i=0;i<n;++i) {
            int c=nums[i]%k;
            for(int j=0;j<k;++j) {
                y[j]=0;
            }
            for(int j=0;j<k;++j) {
                long long mul=1LL*j*c;
                int idx=(int)(mul%k);
                y[idx]+=x[j];
            }
            y[c]+=1;
            for(int j=0;j<k;++j) {
                res[j]+=y[j];
            }
            for(int j=0;j<k;++j) {
                long long temp=x[j];
                x[j]=y[j];
                y[j]=temp;
            }
        }
        return res;
    }
};


