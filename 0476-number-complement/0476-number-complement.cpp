class Solution {
public:
    int findComplement(int num) {
        string r;
        int ans=0;
        while(num!=0) {r=(num%2==0 ?"1":"0")+r; num/=2;}
        for(int i=r.length()-1;i>=0;i--){
            if(r[i]=='0')continue;
            else{
                ans+=pow(2,r.length()-1-i);
            }
        }
        return ans;
    }
};