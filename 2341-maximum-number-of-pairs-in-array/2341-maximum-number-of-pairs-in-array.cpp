class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int arr[101]={0};
        if(nums.size()==1)return {0,1};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        int par=0,lef=0;
        for(int i=0;i<101;i++){
            if(arr[i]%2==0 && arr[i]!=0)par=par+arr[i]/2;
            else if(arr[i]%2!=0){
                lef++;
                par=par+(arr[i]-1)/2;
            }
        }
        cout<<lef<<endl;
        return {par,lef};
    }
};