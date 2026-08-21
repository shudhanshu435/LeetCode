class Solution {
public:
    long long lcm(long long a,long long b){
        return (a/__gcd(a,b))*b;
    }

    long long countMultiples(long long mid,const vector<int>& coins){
        long long total=0;
        int n=coins.size();
        for(int mask=1;mask<(1<<n);++mask){
            long long currentLcm=1;
            int bitsCount=0;
            bool overflow=false;
            for(int i=0;i<n;++i){
                if(mask&(1<<i)){
                    bitsCount++;
                    currentLcm=lcm(currentLcm,coins[i]);
                    if(currentLcm>mid){
                        overflow=true;
                        break;
                    }
                }
            }
            if(!overflow){
                if(bitsCount%2==1){
                    total+=mid/currentLcm;
                }else{
                    total-=mid/currentLcm;
                }
            }
        }
        return total;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());
        vector<int> filteredCoins;
        for(int c:coins){
            bool redundant=false;
            for(int keep:filteredCoins){
                if(c%keep==0){
                    redundant=true;
                    break;
                }
            }
            if(!redundant) filteredCoins.push_back(c);
        }

        long long l=1;
        long long r=(long long)filteredCoins[0]*k;
        long long ans=r;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(countMultiples(mid,filteredCoins)>=k){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};