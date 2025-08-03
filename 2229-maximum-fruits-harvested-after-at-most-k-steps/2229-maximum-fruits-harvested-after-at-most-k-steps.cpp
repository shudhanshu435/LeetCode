class Solution {
public:
    int f(int l , int r,vector<int>& prefix){
        if(l>r) return 0 ;
        return prefix[r]-((l>0)? prefix[l-1] : 0);
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        int n = fruits.size();
        int maxi = fruits.back()[0];
        int ans = 0;
        vector<int>prefix(maxi+1);
        for(auto it : fruits){
            prefix[it[0]]=it[1];
        }
        for(int i = 1 ; i <maxi+1 ; i++){
            prefix[i]+=prefix[i-1];
        }

        int left = max(start-k,0);
        for(int right = left ; right <= min(start + k, maxi); right++){
           while (left <= right &&
                  !( (2 * (start - left) + (right - start) <= k) ||
                     (2 * (right - start) + (start - left) <= k) )) {
                left++;
            }
            if(left<=right){
                ans=max(ans,f(left,right,prefix));
            }
        }

        return ans ;
    }
};