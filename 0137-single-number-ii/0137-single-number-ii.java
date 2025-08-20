class Solution {
    public int singleNumber(int[] nums) {
        int s=0,ps;
        for(int i=0;i<32;i++){
            ps=0;
            for(int j:nums){
                if((j&(1<<i))!=0)ps++;
            }
            if(ps%3!=0)s|=(1<<i);
        }
        return s;
    }
}