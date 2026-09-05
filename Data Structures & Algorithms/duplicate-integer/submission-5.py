class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        arr = []

        for num in nums:
            if num in arr:
                return True
            arr.append(num)

        return False
        