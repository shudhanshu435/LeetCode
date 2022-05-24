class Solution {
public:
    string intToRoman(int num) {
        //we will will two extra arrays to solve the problem
        int arr[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        for(int i=0;i<13;i++){
            while(num>=arr[i]){
                ans+=s[i];
                num-=arr[i];
            }
        }
        return ans;
    }
};