class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0],b=nums[1],c=nums[2];
        if(a+b>c and b+c>a and a+c>b){
            if(a!=b and b!=c and a!=c)return "scalene";
            if(a==b and b==c)return "equilateral";
            return "isosceles";
        }
        return "none";
    }
};