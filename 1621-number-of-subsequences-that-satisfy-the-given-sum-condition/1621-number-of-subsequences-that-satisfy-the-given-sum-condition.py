class Solution:
    mod=10**9+7
    mp={}
    def precompute(self, n):
        self.mp[0] = 0
        for i in range(1, n + 1):
            self.mp[i] = (pow(2, i, self.mod) - 1 + self.mp[i - 1]) % self.mod

    def numSubseq(self, nums: List[int], target: int) -> int:
        n = len(nums)
        self.precompute(n)
        nums.sort()
        ans = 0
        for i in nums:
            if i + i <= target:
                ans += 1
        for i in range(n):
            if nums[i] < target:
                num = target - nums[i]
                ind = self.upper_bound(nums, num) - 1
                ind -= i + 1
                if ind < 0:
                    break
                ans = (ans + self.mp[ind] + ind + 1) % self.mod
        return ans

    def upper_bound(self, nums, target):
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) // 2
            if nums[mid] <= target:
                low = mid + 1
            else:
                high = mid
        return low