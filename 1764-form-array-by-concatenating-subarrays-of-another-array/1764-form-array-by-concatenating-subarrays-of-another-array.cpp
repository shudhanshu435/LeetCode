class Solution {
public:
    vector<int> lps(vector<int>&s){
        int n=s.size();
        vector<int>v(n,0);
        int len=0,i=1;
        while(i<n){
            if(s[len]==s[i]){
                len++;
                v[i]=len;
                i++;
            }
            else{
                if(len==0)i++;
                else len=v[len-1];
            }
        }
        return v;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n=nums.size(),cnt=0,j=0;
        for(auto &i:groups){
            vector<int>v=lps(i);
            int kk=0;
            int m=i.size();
            if(m>n)return 0;
            while(j<n){
                if(nums[j]==i[kk]){
                    j++;kk++;
                    if(kk==m){
                        cnt++;
                        break;
                    }
                }
                else{
                    if(kk==0)j++;
                    else kk=v[kk-1];
                }
            }
        }
        if(cnt==groups.size())return 1;
        return 0;
    }
};