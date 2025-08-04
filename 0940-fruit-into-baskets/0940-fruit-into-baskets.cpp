class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // this problem is finding max length subarray of two elements
        int k=0,ans=0;
        unordered_map<int,int>mp;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            if(mp.size()>2){
                mp[fruits[k]]--;
                if(mp[fruits[k]]==0)mp.erase(fruits[k]);
                k++;
            }
            ans=max(ans,i-k+1);
        }
        return ans;
    }
};