class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target in nums:
            return nums.index(target)
        cnt = 0
        for i in nums:
            if i > target:
                return cnt
            cnt += 1
        return cnt
