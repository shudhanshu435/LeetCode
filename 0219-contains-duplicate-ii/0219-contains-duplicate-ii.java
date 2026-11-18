class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<>();
        int n=nums.length;
        int i=0;
        for(;i<Math.min(k+1,n);i++){
            set.add(nums[i]);
        }
        if(set.size()!=Math.min(k+1,n))return true;

        int s=0;
        for(;i<n;i++){
            set.remove(nums[s]);
            set.add(nums[i]);
            s++;
            if(set.size()!=k+1)return true;
        }
        return false;


    }
}