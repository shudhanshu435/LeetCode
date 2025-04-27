class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        n=len(nums)
        cnt=0
        for i in range(1,n-1):
            if nums[i-1]+nums[i+1]==nums[i]/2:
                cnt+=1
        return cnt