class Solution {
public:
    int divisorSubstrings(int num, int k) {
     ostringstream str1;
     str1 << num;
     int cnt=0;
     string geek = str1.str();
     for(int i=0;i<geek.length()-k+1;i++){
         string s=geek.substr(i,k);
         stringstream geek(s);
         int x = 0;
         geek >> x;
         if(x*1==0)continue;
         if(num%x==0)cnt++;
        }
        return cnt;
    }
};
