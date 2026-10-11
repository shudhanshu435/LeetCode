class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        sum=0
        l=len(nums)
        for i in range(len(nums)):
            if l%(i+1)==0:
                sum+=nums[i]*nums[i]
        return sum