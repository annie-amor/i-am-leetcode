class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <=2:
            return max(nums)
        
        cache = [0]*(len(nums)+1)
        cache[1], cache[2] = nums[0], nums[1]

        for i in range(2, len(nums)):
            robFirst = cache[i-2] + nums[i]
            robSecond = cache[i-1] + nums[i]
            cache[i+1] = max(robFirst, robSecond)
        
        return max(cache)
