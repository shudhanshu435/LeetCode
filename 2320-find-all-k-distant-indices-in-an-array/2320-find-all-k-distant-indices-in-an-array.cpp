class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                s.insert(i);
                int l=i-1,c=k;
                while(l>=0 and c--){
                    s.insert(l);
                    l--;
                }
                int r=i+1;c=k;
                while(r<n and c--){
                    s.insert(r);
                    r++;
                }
            }
        }
        vector<int>v(s.begin(),s.end());
        return v;
    }
};