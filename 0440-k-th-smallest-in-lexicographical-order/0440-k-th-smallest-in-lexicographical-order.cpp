class Solution {
public:
    int Count(long long curr, long long next, int n){
        int count=0;
        while(curr<=n){
            count+=next-curr;
            curr*=10;
            next*=10;

            next=min(next,(long long)(n+1));
        }
        return count;

    }
    int findKthNumber(int n, int k) {
        // vector<string>vec;
        // for(int i=0;i<n;i++){
        //     vec.push_back(to_string(i+1));
        // }
        // sort(vec.begin(),vec.end());
        // return stoi(vec[k-1]);

        long long curr_prefix=1;
        k-=1;
        while(k>0){
            int cnt=Count(curr_prefix, curr_prefix+1, n);
            if(cnt<=k){
                curr_prefix+=1;
                k-=cnt;
            }
            else{
                curr_prefix*=10;
                k-=1;
            }
        }
        return curr_prefix;
    }
};