class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        std::rotate(nums.begin(),nums.end()-(k%n),nums.end());
    }
};

// 1 2 3 4 5 6 7
// 7 6 5 4 3 2 1

// 5 6 7 1 2 3 4