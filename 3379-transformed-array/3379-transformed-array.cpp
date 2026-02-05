class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            int mov=abs(nums[i]%n);
            int f;
            if(nums[i]<0){
                f=i+n-mov;
                // vec[i]=nums[(i-mov+n)%n];
            }
            else{
                f=i+mov;
            }
            vec[i]=nums[(f+n)%n];
        }
        return vec;
    }
};

// x - forward
// n-x - backward