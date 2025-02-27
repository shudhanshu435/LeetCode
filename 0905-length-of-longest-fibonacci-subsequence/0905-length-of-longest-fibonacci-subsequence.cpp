class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        long long cnt=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                long long a=arr[i];
                long long b=arr[j];
                cnt=2;
                while(1){
                    long long newsum=a+b;
                    auto it=lower_bound(arr.begin(),arr.end(),newsum);
                    int ind=distance(arr.begin(),it);

                    if(ind<n and arr[ind]==newsum){
                        a=b;
                        b=*it;
                        cnt++;
                    }
                    else{
                        ans=max(ans,cnt);
                        break;
                    }
                }
            }
        }
        if(ans<3)return 0;
        return ans;
    }
};