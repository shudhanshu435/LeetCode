class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<=0)return false;
        double l=Math.log(n)/Math.log(2);
        if((1<<(int)l)==n)return true;
        return false;
    }
}