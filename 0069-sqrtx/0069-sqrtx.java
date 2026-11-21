class Solution {
    public int mySqrt(int x) {
        long i=1;
        while(true){
            if(i*i==x)return (int)i;
            if(i*i>x)return (int)i-1;
            i++;
        }
    }
}