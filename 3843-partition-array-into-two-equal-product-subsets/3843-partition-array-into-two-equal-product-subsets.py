class Solution:
    def checkEqualPartitions(self, nums: List[int], target: int) -> bool:
        val=1
        for i in nums:
            val=val*i
        if target*target==val:
            return True
        else:
            return False