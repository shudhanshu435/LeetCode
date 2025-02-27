class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            long long cnt=1;
            for(int j=i+1;j<n-1;j++){
                long long a=arr[i];
                int ind=j;
                cnt=2;
                long long b=arr[j];
                // int c=a+b;
                bool nf=0;
                while(ind<n){
                    long long newsum=a+b;
                    // cout<<newsum<<endl;
                    auto it=lower_bound(arr.begin(),arr.end(),newsum);
                    int ind=distance(arr.begin(),it);
                    // cout<<ind<<endl;
                    if(ind<n and arr[ind]==newsum){
                        a=b;
                        b=*it;
                        cnt++;
                        // cout<<ind<<" "<<cnt<<endl;
                    }
                    else{
                        ans=max(ans,cnt);
                        bool nf=1;
                        break;
                    }
                }
                // if(nf)break;
            }
        }
        if(ans<3)return 0;
        return ans;
    }
};