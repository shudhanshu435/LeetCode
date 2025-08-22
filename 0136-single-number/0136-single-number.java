class Solution {
    public int singleNumber(int[] nums) {
        int xor_val=0;
        for(int i=0;i<nums.length;i++){
            xor_val=xor_val^nums[i];
        }
        return xor_val;
    }
}