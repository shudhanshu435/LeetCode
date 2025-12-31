class Solution {
    public boolean isPowerOfThree(int n) {
        if(n<=0)return false;
        double d=Math.ceil(Math.log(n)/Math.log(3));
        System.out.println(d);
        if(Math.pow(3,(int)d)==(double)n)return true;
        return false;
    }
}