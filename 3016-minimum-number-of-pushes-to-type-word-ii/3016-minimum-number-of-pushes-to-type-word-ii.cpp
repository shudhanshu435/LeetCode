class Solution {
public:
    int minimumPushes(string word) {
        vector<int>vec(26,0);
        for(auto i:word)vec[i-'a']++;
        sort(vec.rbegin(),vec.rend());
        int sum=0;
        // for(auto i:vec)cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<26;i++){
            if(i<=7)sum+=vec[i];
            else if(i<=15)sum+=vec[i]*2;
            else if(i<=23)sum+=vec[i]*3;
            else sum+=vec[i]*4;
        }
        return sum;
    }
};