class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            int sec = target-nums[i];
            if(mp.containsKey(sec))return new int[]{i,mp.get(sec)};
            mp.put(nums[i],i);
        }

        return new int[]{};
    }
}