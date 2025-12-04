class Solution {
public:
    int jump(vector<int>& arr) {
        int max_jump=0;
        int jump=1;
        int n=arr.size();
        int step=arr[0];
        if(n<=1)return 0;
        if(arr[0]==0)return 0;
        for(int i=1;i<n;i++){
            if(i==n-1)return jump;
            max_jump=max(max_jump,i+arr[i]);
            step--;

            if(step==0){
                jump++;
                step=max_jump-i;
                if(step<=0)return -1;
            }
        }
    return jump;
    }
};

// [2,3,1,1,4,5,3]