class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.length();
        vector<long long>preL(n),preLC(n);
        long long c=0,cnt=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='L'){
                c++;
            }
            else if(s[i]=='C'){
                cnt+=c;
            }
            preLC[i]=cnt;
            preL[i]=c;
        }

        // for(auto i:preLC)cout<<i<<" ";
        // cout<<endl;
        vector<long long>sufT(n),sufCT(n);
        c=0,cnt=0;
        for(long long i=n-1;i>=0;i--){
            if(s[i]=='T'){
                c++;
            }
            else if(s[i]=='C'){
                cnt+=c;
            }
            sufCT[i]=cnt;   // "L M C C L C T"
            sufT[i]=c;
        }
        // for(auto i:sufCT)cout<<i<<" ";
        // cout<<endl;
        long long ans=0;
        ans=max(ans,sufCT[0]);
        for(int i=1;i<n;i++){
            ans=max(ans,sufCT[i]); //L
            ans=max(ans,preL[i-1]*sufT[i]); //C
            ans=max(ans,preLC[i-1]); //T
        }
        ans=max(ans,preLC[n-1]);

        for(int i=0;i<n;i++){
            if(s[i]=='C'){
                long long l=(i>0 ? preL[i-1]:0);
                long long t=(i+1 < n ? sufT[i + 1]:0);
                ans += l*t;
            }
        }
        return ans;
    }
};