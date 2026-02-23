class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>sp;
        int n=heights.size();
        vector<int>ans(n,0);
        ans[n-1]=0;
        sp.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!sp.empty() and sp.top()<heights[i]){
                sp.pop();
                cnt++;
            }
            if(!sp.empty())cnt++;
            ans[i]=cnt;
            sp.push(heights[i]);
        }
        return ans;
    }
};