class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>vec(n);
        vec[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            if(i+questions[i][1]+1<n)vec[i]=max((long long)questions[i][0]+vec[i+questions[i][1]+1],vec[i+1]);
            else vec[i]=max(vec[i+1],(long long)questions[i][0]);
        }
        for(auto i:vec)cout<<i<<" ";
        cout<<endl;
        return vec[0];
    }
};