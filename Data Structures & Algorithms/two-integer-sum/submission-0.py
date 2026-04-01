class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        L, R = 0, 0

        while L < len(nums):
            R = 0
            while R < len(nums):

                if L != R and (nums[L] + nums[R]) == target:
                    return [L,R]
                
                R += 1
            L += 1
        
            
        