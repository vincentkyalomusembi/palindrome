class Solution(object):
    def twoSum(self, nums, target):
        counts = 0 #initialize count variable
        for i in range(len(nums)): #iterate through the list
            for j in range(i + 1, len(nums)):#check all pairs
                if nums[i] + nums [j] == target:
                    return[i, j]
        return [] 
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        