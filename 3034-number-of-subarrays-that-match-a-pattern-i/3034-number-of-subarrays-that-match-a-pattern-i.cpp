class Solution {
public:
    vector<int> lps(vector<int>&v){
        int len=0;
        int i=1;
        int n=v.size();
        vector<int>lps(n,0);
        while(i<n){
            if(v[i]==v[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0)i++;
                else len=lps[len-1];
            }
        }
        return lps;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int>v;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])v.push_back(1);
            else if(nums[i]==nums[i-1])v.push_back(0);
            else v.push_back(-1);
        }

        // for(auto i:v)cout<<i<<" ";
        // cout<<endl;

        vector<int>vv=lps(pattern);

        // for(auto i:vv)cout<<i<<" ";
        // cout<<endl;


        int cnt=0;
        n=v.size();
        int p=pattern.size();
        if(p>n)return 0;
        int i=0,j=0;
        while(i<n){
            if(v[i]==pattern[j]){
                i++;j++;
                if(j==p){
                    cnt++;
                    j=vv[j-1];
                }
            }
            else{
                if(j==0)i++;
                else j=vv[j-1];
            }
        }

        return cnt;
    }
};