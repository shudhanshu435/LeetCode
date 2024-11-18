class Solution {
public:
// 5 7 1 4    5 7 1 4
// 12 8 5 9 12 8 5
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>vec(n,0),tec;
        if(k==0)return vec;
        for(int i=0;i<n;i++)code.push_back(code[i]);
        int sum=0,i;
        for(i=0;i<abs(k);i++){
            sum+=code[i];
        }
        tec.push_back(sum);
        int kk=0;
        int s=code.size();
        for(;i<s;i++){
            sum+=code[i];
            sum-=code[kk++];
            tec.push_back(sum);
        }
        for(auto i:tec)cout<<i<<" ";
        vector<int>ans;
        if(k<0)for(int i=n+k;i<n+k+n;i++)ans.push_back(tec[i]);
        else for(int i=1;i<=n;i++)ans.push_back(tec[i]);
        return ans;
    }
};