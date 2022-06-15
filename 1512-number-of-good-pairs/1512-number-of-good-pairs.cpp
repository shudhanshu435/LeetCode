class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int arr[101]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        cout<<arr[4]<<" "<<arr[2]<<endl;
        int sum=0;
        for(int i=0;i<101;i++){
            if(arr[i]>0)sum+=arr[i]*(arr[i]-1)/2;
        }
        return sum;
        
    }
};