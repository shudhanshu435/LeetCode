class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s=num;
        int n=s.length();
        while(k--){
            next_permutation(num.begin(),num.end());
        }
        cout<<num<<endl;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==num[i])continue;
            for(k=i;k<n;k++){
                if(s[k]==num[i])break;
            }
            while(k>i){
                swap(s[k],s[k-1]);
                cnt++;
                k--;
            }
        }

        return cnt;
    }
};